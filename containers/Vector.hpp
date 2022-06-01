#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T, class Allocator = std::allocator<T> >
class Vector {

    public:
    typedef Allocator allocator_type;
    // typedef typename ft::iterator_traits<iterator>::value_type value_type;
    // typedef typename Allocator::value_type                          value_type;
    typedef typename Allocator::size_type                           size_type;
    typedef typename Allocator::pointer                             pointer;
    typedef typename Allocator::const_pointer                       const_pointer;
    typedef typename Allocator::reference                           reference;
    typedef typename Allocator::const_reference                     const_reference;
    
    Vector()
    : _capacity(0), _size(0) {
        _array = _alloc.allocate(_capacity);
    }

    // Vector(const allocator_type& alloc)
    // : _alloc(alloc), _array(NULL), _capacity(0), _size(0) {};

    explicit Vector(size_type size, const T& value = T(), const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _array(NULL), _capacity(size), _size(size){

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
    // difference_type range = last - first;
    // reserve(range);
    // _size = range;
    // for (size_type i = 0; i < size(); i++) {
    //   _alloc.construct(_arr + i, *(first++));
    // }
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
        // _size = 0;
        // _array = nullptr;
        // std::cout << "3333" << std::endl;
    }

    Vector<T> & operator=(const Vector<T> &rhs) {
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

    // std::cout << "ELEMENT ACCESS" << std::endl;

    reference operator[](size_type index) { return _array[index]; }
    const_reference operator[](size_type index) const { return _array[index]; }

    reference front() { return *_array; }
    const_reference front() const { return *_array; }

    reference back() { return *(_array + _size - 1); }
    const_reference back() const{ return *(_array + _size - 1); }


    allocator_type get_allocator() const { return _alloc; };
    size_type size() const { return _size; }
    size_type max_size() const { return _alloc.max_size(); };
    size_type capacity() const { return _capacity; }
    
    
    void reserve(size_type new_cap) {
        if (_capacity >= new_cap) {
            return;
        }
        if (new_cap > max_size()) {
            throw std::length_error("New capacity is greater than max_size");
        }

        T* tmp = _alloc.allocate(new_cap);
        try {
            std::uninitialized_copy(_array, _array + _size, tmp);
        } catch (const std::exception&) {
            _alloc.deallocate(tmp, _size);
            throw;
        }
        for (size_type i = 0; i < _size; ++i) {
            _alloc.destroy(_array + i);
        }
        _alloc.deallocate(_array, _capacity);
        this->_array = tmp;
        this->_capacity = new_cap;
    }

    void push_back(const T& new_elem) {
        if (_size == _capacity) {
            size_type new_cap = (_capacity == 0) ? 1 : _capacity *= 2; 
            reserve(new_cap);
        }
        _alloc.construct(_array + _size, new_elem);
        ++_size;
    }

    void pop_back() {
        --_size;
        //(arr + sz) -> ~T();
    }


    void resize(size_type size, T value = 0) {
        if (size < 0)
            throw std::length_error("Size couldn't be less then 0!");
        if (size < this->_size) {
            for (size_type i = size; i < _size; ++i) {
                _array[i] = 0;
            }
            this->_size = size;
        }
        else if (size > this->_size) {
            if ((this->_size + size) > _capacity) {
                _capacity *= 2; 
                T* tmp = new T[_capacity];
                for (size_type i = 0; i < _size; ++i) {
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

    void clear() {
        _size = 0;
    }




    bool empty() const { return _size > 0 ? false : true; }

    private:
    allocator_type _alloc;
    T*      _array;
    size_type  _capacity;
    size_type  _size;


};


void vector_test();

#endif
