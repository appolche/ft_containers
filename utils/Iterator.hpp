#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

    template <typename Iterator>
    struct iterator_traits {
      typedef typename Iterator::difference_type    difference_type;
      typedef typename Iterator::value_type         value_type;
      typedef typename Iterator::pointer            pointer;
      typedef typename Iterator::reference          reference;
      typedef typename Iterator::iterator_category  iterator_category;
    };

    template <typename T>
    struct iterator_traits<T*> {
      typedef ptrdiff_t                       difference_type;
      typedef T                               value_type;
      typedef T*                              pointer;
      typedef T&                              reference;
      typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename T>
    struct iterator_traits<const T*> {
      typedef ptrdiff_t                       difference_type;
      typedef T                               value_type;
      typedef const T*                        const_pointer;
      typedef const T&                        const_reference;
      typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename T>
    class RandomAccessIterator {
      public:
        typedef typename std::random_access_iterator_tag iterator_category;
        typedef std::ptrdiff_t                           difference_type; //std::ptrdiff_t тип х-зующий разницу между итераторами (типа инта)
        typedef T                                        value_type;
        typedef T*                                       pointer;
        typedef const T*                                 const_pointer;
        typedef T&                                       reference;
        typedef const T&                                 const_reference;

        RandomAccessIterator() : _ptr(NULL) {};
        RandomAccessIterator(pointer ptr) : _ptr(ptr) {};
        RandomAccessIterator(const RandomAccessIterator& other) { *this = other; };

        RandomAccessIterator& operator=(const RandomAccessIterator& other) {
          _ptr = other._ptr;
          return *this;
        };

        reference operator*() { return *_ptr; }
        pointer operator->() { return _ptr; }

        const_reference operator*() const { return *_ptr; }
        const_pointer operator->() const { return _ptr; }

        RandomAccessIterator operator++() {
          ++_ptr;
          return *this;
        }

        RandomAccessIterator operator++(int) {
          RandomAccessIterator tmp = *this;
          ++_ptr;
          return tmp;
        }

        RandomAccessIterator operator--() {
          --_ptr;
          return *this;
        }

        RandomAccessIterator operator--(int) {
          RandomAccessIterator tmp = *this;
          --_ptr;
          return tmp;
        }

        RandomAccessIterator& operator+=(difference_type n) {
          _ptr += n;
          return *this;
        }

        RandomAccessIterator operator+(difference_type n) {
          RandomAccessIterator copy = *this;
          copy += n;
          return copy;
        }

        RandomAccessIterator& operator-=(difference_type n) {
          _ptr -= n;
          return *this;
        }

        RandomAccessIterator operator-(difference_type n) {
          RandomAccessIterator copy = *this;
          copy -= n;
          return copy;
        }

        friend difference_type operator-(const RandomAccessIterator& lhs,
                                        const RandomAccessIterator& rhs) {
          return lhs._ptr - rhs._ptr;
        }

        friend bool operator==(const RandomAccessIterator& lhs,
                              const RandomAccessIterator& rhs) {
          return lhs._ptr == rhs._ptr;
        }
        friend bool operator!=(const RandomAccessIterator& lhs,
                              const RandomAccessIterator& rhs) {
          return lhs._ptr != rhs._ptr;
        }
        friend bool operator>(const RandomAccessIterator& lhs,
                              const RandomAccessIterator& rhs) {
          return lhs._ptr > rhs._ptr;
        }
        friend bool operator>=(const RandomAccessIterator& lhs,
                              const RandomAccessIterator& rhs) {
          return lhs._ptr >= rhs._ptr;
        }
        friend bool operator<(const RandomAccessIterator& lhs,
                              const RandomAccessIterator& rhs) {
          return lhs._ptr < rhs._ptr;
        }
        friend bool operator<=(const RandomAccessIterator& lhs,
                              const RandomAccessIterator& rhs) {
          return lhs._ptr <= rhs._ptr;
        }

      private:
        pointer _ptr;
      };

      /*
      **=========================================================================
      **     Reverse Iterator
      **=========================================================================
      */

      template <typename T>
      class ReverseIterator {
      public:
        typedef typename std::random_access_iterator_tag  iterator_category;
        typedef T                                         value_type;
        typedef std::ptrdiff_t                            difference_type;
        typedef T*                                        pointer;
        typedef const T*                                  const_pointer;
        typedef T&                                        reference;
        typedef const T&                                  const_reference;

        ReverseIterator() : _ptr(NULL){};
        ReverseIterator(pointer ptr) : _ptr(ptr){};
        ReverseIterator(const ReverseIterator& other) { *this = other; };

        ReverseIterator& operator=(const ReverseIterator& other) {
          _ptr = other._ptr;
          return *this;
        };

        reference operator*() { return *_ptr; }
        pointer operator->() { return _ptr; }

        const_reference operator*() const { return *_ptr; }
        const_pointer operator->() const { return _ptr; }

        ReverseIterator operator++() {
          --_ptr;
          return *this;
        }

        ReverseIterator operator++(int) {
          ReverseIterator tmp = *this;
          --_ptr;
          return tmp;
        }

        ReverseIterator operator--() {
          ++_ptr;
          return *this;
        }

        ReverseIterator operator--(int) {
          ReverseIterator tmp = *this;
          ++_ptr;
          return tmp;
        }

        ReverseIterator& operator+=(difference_type n) {
          _ptr -= n;
          return *this;
        }

        ReverseIterator operator+(difference_type n) {
          ReverseIterator copy = *this;
          copy += n;
          return copy;
        }

        ReverseIterator& operator-=(difference_type n) {
          _ptr += n;
          return *this;
        }

        ReverseIterator operator-(difference_type n) {
          ReverseIterator copy = *this;
          copy -= n;
          return copy;
        }

        friend difference_type operator-(const ReverseIterator& lhs,
                                        const ReverseIterator& rhs) {
          return rhs._ptr - lhs._ptr;
        }

        friend bool operator==(const ReverseIterator& lhs,
                              const ReverseIterator& rhs) {
          return lhs._ptr == rhs._ptr;
        }
        friend bool operator!=(const ReverseIterator& lhs,
                              const ReverseIterator& rhs) {
          return lhs._ptr != rhs._ptr;
        }
        friend bool operator>(const ReverseIterator& lhs,
                              const ReverseIterator& rhs) {
          return lhs._ptr < rhs._ptr;
        }
        friend bool operator>=(const ReverseIterator& lhs,
                              const ReverseIterator& rhs) {
          return lhs._ptr <= rhs._ptr;
        }
        friend bool operator<(const ReverseIterator& lhs,
                              const ReverseIterator& rhs) {
          return lhs._ptr > rhs._ptr;
        }
        friend bool operator<=(const ReverseIterator& lhs,
                              const ReverseIterator& rhs) {
          return lhs._ptr >= rhs._ptr;
        }

      private:
        pointer _ptr;
    };

}

#endif