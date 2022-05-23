#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector {

    public:
    Vector() { _capacity = 0; _array = new T[_capacity]; _size = 0; }
    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }
    void push_back(const T& new_elem) {
        
        int i = -1;
        if (_capacity == _size) { 
            _capacity = (_capacity == 0) ? 1 : _capacity *= 2; 
        }

        T* tmp = new T[_capacity];
            
        while (_array[++i]) {
                tmp[i] = _array[i];
            }
            tmp[_size] = new_elem;
            delete _array;
            _array = tmp;
            ++_size;

    }
    

    private:
    T*      _array;
    size_t  _size;
    size_t  _capacity;


};

#endif
