#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector {

    public:
    Vector(): _array(new T[0]), _capacity(0), _size(0) {}
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
            for (int i = 0; i < _size; i++) {
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

    T getElemByIndex(int index) const {
        return _array[index];
    }

    T& at(size_t index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index is out of bounds!");
        }
        return _array[index];
    }

    T& operator[](size_t index) const {
        return _array[index];
    }

    private:
    T*      _array;
    size_t  _capacity;
    size_t  _size;


};

#endif
