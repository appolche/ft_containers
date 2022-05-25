#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector {

    public:
    Vector(): _array(new T[0]), _capacity(0), _size(0) {}
    Vector(size_t size, T value = 0): _array(new T[size]), _capacity(size), _size(size) {
        for (size_t i = 0; i < _size; ++i)
            this->_array[i] = value;
    }
    Vector(const Vector<T> &rhs): _array(new T[rhs._size]), _capacity(rhs._size), _size(rhs._size) {
        for (size_t i = 0; i < rhs._size; ++i)
            this->_array[i] = rhs._array[i];
    }
    ~Vector() { delete[] _array; }

    Vector<T> & operator=(const Vector<T> &rhs) {
        if (this != &rhs) {
            delete[] _array;
            _array = new T[rhs._size];
            _size = rhs._size;
            _capacity = rhs._size;
            for (size_t i = 0; i < _size; i++) {
                _array[i] = rhs._array[i];
            }
        }
        return *this;
    }


    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }
    void push_back(const T& new_elem) {
        if (_capacity > _size) {
            _array[_size] = new_elem;
            _size++;
        }
        else {
            if (_capacity == _size) { 
                _capacity = (_capacity == 0) ? 1 : _capacity *= 2; 
            }
            T* tmp = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                tmp[i] = _array[i];
            }
            tmp[_size] = new_elem;
            delete[] _array;
            _array = tmp;
            ++_size;
        }
    }

    void pop_back() {
        --_size;
    }

    void resize(size_t size, T value = 0) {
        if (size < 0)
            throw std::length_error("Size couldn't be less then 0!");
        if (size < this->_size) {
            for (size_t i = size; i < _size; ++i) {
                _array[i] = 0;
            }
            this->_size = size;
        }
        else if (size > this->_size) {
            if ((this->_size + size) > _capacity) {
                _capacity *= 2; 
                T* tmp = new T[_capacity];
                for (size_t i = 0; i < _size; ++i) {
                    tmp[i] = _array[i];
                }
                delete[] _array;
                _array = tmp;
            }
            for (; _size < size; ++_size) {
                _array[_size] = value;
            }
        }
    }

    void swap(Vector<T>& rhs) {

        Vector<T> tmp;

        delete[] tmp._array;
        tmp._array = new T[rhs._capacity];
        tmp._size = rhs._size;
        tmp._capacity = rhs._capacity;
        for (size_t i = 0; i < _size; i++) {
            tmp._array[i] = rhs._array[i];
        }

        delete[] rhs._array;
        rhs._array = new T[this->_capacity];
        rhs._size = this->_size;
        rhs._capacity = this->_capacity;
        for (size_t i = 0; i < _size; i++) {
            rhs._array[i] = this->_array[i];
        }

        delete[] this->_array;
        this->_array = new T[tmp._capacity];
        this->_size = tmp._size;
        this->_capacity = tmp._capacity;
        for (size_t i = 0; i < _size; i++) {
            this->_array[i] = tmp._array[i];
        }
    }

    T& at(size_t index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index is out of bounds!");
        }
        return _array[index];
    }

    T& at(size_t index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index is out of bounds!");
        }
        return _array[index];
    }

    T& operator[](size_t index) { return _array[index]; }
    T& operator[](size_t index) const { return _array[index]; }

    T& front() { return *_array; }
    T& front() const { return *_array; }

    T& back() { return *(_array + _size - 1); }
    T& back() const{ return *(_array + _size - 1); }

    bool empty() const { return _size > 0 ? false : true; }

    private:
    T*      _array;
    size_t  _capacity;
    size_t  _size;


};


void vector_test();

#endif
