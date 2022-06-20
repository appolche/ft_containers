#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../utils/Iterator.hpp"
#include "../utils/Type_traits.hpp"
#include "../utils/Pair.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<Pair<const Key, T>>>
	class map {
	public:
		typedef Key 													key_type;
		typedef T 														mapped_type;
		typedef Pair<const key_type, mapped_type>				value_type;
		typedef Compare												key_compare;

		typedef Allocator											 	allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;

		typedef ft::bidirectional_iterator_tag<T>::value_type iterator;
		typedef ft::bidirectional_iterator_tag<T>::const_value_type const_iterator;
		
		typedef ft::ReverseIterator<T> reverse_iterator;
		typedef ft::ReverseIterator<const T> const_reverse_iterator;
		typedef iterator_traits<iterator>::difference_type difference_type;

		class value_compare {
			friend class map;

			protected:
			key_compare comp;
			value_compare(key_compare c) : comp(c){};

			public:
			bool operator()(const value_type& lhs, const value_type& rhs) const {
				return comp(lhs.first, rhs.first);
			};
			~value_compare();
		};


		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

		map(const map &x);

		~map;

		map &operator=(const map &x);

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		mapped_type &operator[](const key_type &k);

		// single element
		pair<iterator, bool> insert(const value_type &val);
		// with hint
		iterator insert(iterator position, const value_type &val);
		// range
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);

		void erase(iterator position);
		size_type erase(const key_type &k);
		void erase(iterator first, iterator last);

		void swap(map &x);
		void clear();

		key_compare key_comp() const;
		value_compare value_comp() const;
		iterator find(const key_type &k);
		const_iterator find(const key_type &k) const;
		size_type count(const key_type &k) const;
		iterator lower_bound(const key_type &k);
		const_iterator lower_bound(const key_type &k) const;
		iterator upper_bound(const key_type &k);
		const_iterator upper_bound(const key_type &k) const;
		pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
		pair<iterator, iterator> equal_range(const key_type &k);
		allocator_type get_allocator() const;

	protected:
		container_type c;
	};
} // namespace ft

#endif
