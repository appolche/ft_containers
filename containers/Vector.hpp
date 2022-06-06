#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../utils/Iterator.hpp"

namespace ft {

    template <typename T, class Allocator = std::allocator<T> >
    class Vector {

        public:
            typedef Allocator                                               allocator_type;
            typedef typename Allocator::size_type                           size_type;
            typedef typename Allocator::pointer                             pointer;
            typedef typename Allocator::const_pointer                       const_pointer;
            typedef typename Allocator::reference                           reference;
            typedef typename Allocator::const_reference                     const_reference;

            typedef ft::RandomAccessIterator<T>                             iterator;
            typedef ft::RandomAccessIterator<const T>                       const_iterator;
            typedef ft::ReverseIterator<T>                                  reverse_iterator;
            typedef ft::ReverseIterator<const T>                            const_reverse_iterator;

            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<iterator>::value_type      value_type;
            
            Vector()
            : _array(NULL), _capacity(0), _size(0) {}

            explicit Vector(const allocator_type& alloc)
            : _alloc(alloc), _array(NULL), _capacity(0), _size(0) {}

            explicit Vector(size_type size, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
                : _alloc(alloc), _array(NULL), _capacity(size), _size(size) {
                _array = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; ++i) {
                    _alloc.construct(_array + i, value);
                }
            }

            // template <class InputIt>
            // Vector(InputIt first, InputIt last,
            //      const allocator_type& alloc = allocator_type(),
            //      typename ft::enable_if<!ft::is_integral<InputIt>::value,
            //                             InputIt>::type* = NULL)
            //   : _arr(NULL), _size(0), _capacity(0), _alloc(alloc) {
            //     difference_type range = last - first;
            //     reserve(range);
            //     _size = range;
            //     for (size_type i = 0; i < size(); i++) {
            //         _alloc.construct(_arr + i, *(first++));
            //     }
            // };

            Vector(const Vector& rhs)
            :  _alloc(rhs._alloc), _array(_alloc.allocate(rhs._size)), _capacity(rhs._size), _size(rhs._size) {
                for (size_type i = 0; i < rhs._size; ++i) {
                    _alloc.construct(_array + i, rhs._array[i]);
                }
            }

            ~Vector() { 
                for (size_type i = 0; i < _size; ++i){
                    _alloc.destroy(_array + i);
                }
                _alloc.deallocate(_array, _capacity); 
            }

            Vector<T> & operator=(const Vector& rhs) {
                if (this != &rhs) {
                    this->~Vector();
                    _size = rhs._size;
                    _capacity = rhs._size;
                    _array = _alloc.allocate(rhs._size);
                    for (size_type i = 0; i < _size; i++) {
                        _alloc.construct(_array + i, rhs._array[i]);
                    }
                }
                return *this;
            }

            void assign(size_type count, const value_type& value) {
                if (count > _capacity) {
                    reserve(count);
                }
                for (size_type i = 0; i < count; ++i) {
                    _alloc.construct(_array + i, value);
                }
                _size = count;
            }

            //template <class InputIt>
            //void assign(InputIt first, InputIt last,
            //   typename ft::enable_if<!ft::is_integral<InputIt>::value,
            //      InputIt>::type* = NULL) {
            //   size_type count = static_cast<size_type>(std::distance(first, last));
            //   if (count > capacity()) {
            //       reserve(count);
            //   }
            //   for (size_type i = 0; i < count; ++i) {
            //      _alloc.construct(_arr + i, *(first++));
            //   }
            //   _size = count;
            //}
            
            // std::cout << "ITERATORS" << std::endl;
            iterator begin() { return iterator(_array); }
            const_iterator begin() const { return const_iterator(_array); }

            iterator end() { return iterator(_array + _size); }
            const_iterator end() const { return const_iterator(_array + _size); }

            reverse_iterator rbegin() { return reverse_iterator(_array + _size - 1); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(_array + _size - 1); }

            reverse_iterator rend() { return reverse_iterator(_array - 1); }
            const_reverse_iterator rend() const { return const_reverse_iterator(_array - 1); }

            // std::cout << "ELEMENT ACCESS" << std::endl;

            reference at(size_type index) {
                if (index < 0 || index >= _size) {
                    throw std::out_of_range("Index is out of bounds!");
                }
                return _array[index];
            }

            const_reference at(size_type index) const {
                if (index < 0 || index >= _size) {
                    throw std::out_of_range("Index is out of bounds!");
                }
                return _array[index];
            }

            reference operator[](size_type index) { return _array[index]; }
            const_reference operator[](size_type index) const { return _array[index]; }

            reference front() { return *_array; }
            const_reference front() const { return *_array; }

            reference back() { return *(_array + _size - 1); }
            const_reference back() const{ return *(_array + _size - 1); }


            // std::cout << " CAPACITY " << std::endl;

            bool empty() const { return _size > 0 ? false : true; }
            size_type size() const { return _size; }
            size_type capacity() const { return _capacity; }
            size_type max_size() const { return _alloc.max_size(); };
            
            void resize(size_type size, value_type value = value_type()) {
                // if (size < 0)
                //     throw std::length_error("Size couldn't be less then 0!"); // ?strong except guarant?
                if (size < this->_size) {
                    for (size_type i = size; i < this->_size; ++i) {
                        _alloc.destroy(_array + i);
                    }
                }
                else if (size > this->_size) {
                    for (size_type i = this->_size; i < size; ++i) {
                        try {  // is it neccecery to try catch this?
                            push_back(value);
                        } catch (const std::exception&) {
                            for (size_type j = this->_size; j < i; ++j) {
                                _alloc.destroy(_array + j);
                            }
                            throw; // ?strong except guarant?
                        }
                    }
                }
                this->_size = size;
            }

            void reserve(size_type new_cap) {
                if (_capacity >= new_cap) {
                    return;
                }
                if (new_cap > max_size()) {
                    throw std::length_error("New capacity is greater than max_size");
                }

                value_type* tmp = _alloc.allocate(new_cap);
                try {
                    std::uninitialized_copy(_array, _array + _size, tmp);
                } catch (const std::exception&) {
                    _alloc.deallocate(tmp, _size);
                    throw; // ?strong except guarant?
                }
                for (size_type i = 0; i < _size; ++i) {
                    _alloc.destroy(_array + i);
                }
                _alloc.deallocate(_array, _capacity);
                this->_array = tmp;
                this->_capacity = new_cap;
            }

            // std::cout << " MODIFIERS " << std::endl;

            void clear() {
                for (size_type i = 0; i < _size; i++) {
                    _alloc.destroy(_array + i);
                }
                _size = 0;
            }
            
            iterator insert(iterator pos, const value_type& value) {
                size_type insertIdx = static_cast<size_type>(std::distance(begin(), pos));
                insert(pos, 1, value);
            return iterator(_array + insertIdx);
            }

            void insert(iterator pos, size_type count, const value_type& value) {
                try {
                    value_type x = value;
                } catch (...) {
                    throw;
                }
                if (count == 0) return;
                size_type insertIdx = static_cast<size_type>(std::distance(begin(), pos));
                if (_size + count > _capacity) {
                    int newCapacity = _capacity * 2 >= _size + count ? _capacity * 2 : _size + count;
                    reserve(newCapacity);
                }
                if (empty()) {
                    assign(count, value);
                } else {
                        for (size_type i = size() - 1; i >= insertIdx; --i) {
                            _alloc.construct(_array + i + count, _array[i]);
                            if (i == 0) break;
                    }
                    for (size_type i = 0; i < count; ++i) {
                        _alloc.construct(_array + insertIdx++, value);
                        _size++;
                    }
                }
            }

            void push_back(const value_type& new_elem) {
                if (_size == _capacity) {
                    size_type new_cap = (_capacity == 0) ? 1 : (_capacity * 2); 
                    reserve(new_cap);
                }
                _alloc.construct(_array + _size, new_elem);
                ++_size;
            }

            void pop_back() {
                _alloc.destroy(_array + _size - 1);
                --_size;
            }

            void swap(Vector& rhs) {

                pointer tmp_array;
                size_type tmp_size;
                size_type tmp_capacity;
                allocator_type tmp_alloc;

                tmp_array = rhs._array;
                tmp_size = rhs._size;
                tmp_capacity = rhs._capacity;
                tmp_alloc = rhs._alloc;

                rhs._array = this->_array;
                rhs._size = this->_size;
                rhs._capacity = this->_capacity;
                rhs._alloc = this->_alloc;

                this->_array = tmp_array;
                this->_size = tmp_size;
                this->_capacity = tmp_capacity;
                this->_alloc = tmp_alloc;
            }

            
            allocator_type get_allocator() const { return _alloc; };
            
            // NON-MEMBER FUNCTIONS
            
            friend bool operator==(const Vector<value_type, allocator_type>& lhs,
                                    const Vector<value_type, allocator_type>& rhs) {
                size_type i = 0;
                size_type j = 0;
                while (i < lhs.size() && j < rhs.size()) {
                    if (lhs._array[i++] != rhs._array[j++]) {
                        return false;
                    }
                }
                return (i == lhs.size()) && (j == rhs.size());
            };

            friend bool operator!=(const Vector<value_type, allocator_type>& lhs,
                                    const Vector<value_type, allocator_type>& rhs) {
                return !(operator==(lhs, rhs));
            };

            friend bool operator<(const Vector<value_type, allocator_type>& lhs,
                                    const Vector<value_type, allocator_type>& rhs) {
                size_type i = 0;
                while (i < lhs.size() && i < rhs.size() && lhs._array[i] == rhs._array[i]) {
                i++;
                }
                return (i != rhs.size() && (i == lhs.size() || lhs._array[i] < rhs._array[i]));
            }

            friend bool operator<=(const Vector<value_type, allocator_type>& lhs,
                                    const Vector<value_type, allocator_type>& rhs) {
                size_type i = 0;
                while (i < lhs.size() && i < rhs.size() && lhs._array[i] == rhs._array[i]) {
                i++;
                }
                return (i == lhs.size() && i == rhs.size()) ||
                    (i != rhs.size() && (i == lhs.size() || lhs._array[i] < rhs._array[i]));
            }

            friend bool operator>(const Vector<value_type, allocator_type>& lhs,
                                    const Vector<value_type, allocator_type>& rhs) {
                size_type i = 0;
                while (i < lhs.size() && i < rhs.size() && lhs._array[i] == rhs._array[i]) {
                i++;
                }
                return (i != lhs.size() && (i == rhs.size() || rhs._array[i] < lhs._array[i]));
            }

            friend bool operator>=(const Vector<value_type, allocator_type>& lhs,
                                    const Vector<value_type, allocator_type>& rhs) {
                size_type i = 0;
                while (i < lhs.size() && i < rhs.size() && lhs._array[i] == rhs._array[i]) {
                i++;
                }
                return (i == rhs.size() && i == lhs.size()) ||
                    (i != lhs.size() && (i == rhs.size() || rhs._array[i] < lhs._array[i]));
            }

            friend void swap(const Vector<value_type, allocator_type>& lhs,
                            const Vector<value_type, allocator_type>& rhs) {
                lhs.swap(rhs);
            }

        private:
            allocator_type _alloc;
            value_type*    _array;
            size_type      _capacity;
            size_type      _size;
    };

} // namespace ft

void vector_test();

#endif
