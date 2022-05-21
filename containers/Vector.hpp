#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector {

        public:
            Vector() {
                _arr = new T[1];
                _capacity = 1;
            }

            size_t size() const { return _size; };
            size_t capacity() const { return _capacity; };
            bool empty() const { return (_size == 0); };
            // void resize(size_t n, const T& value = T()) {}
            // void reserve(size_t n) {}


        private:
            T* _arr;
            size_t _size;
            size_t _capacity;

};

#endif
