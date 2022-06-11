#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "../utils/Iterator.hpp"
#include "../utils/Type_traits.hpp"
#include "./Vector.hpp"

namespace ft {
	template <typename T, class Container = ft::Vector<T> >
	class Stack {
		/*
		=========================================================================
		Member types
		=========================================================================
		*/
		public:
			typedef Container                                               container_type;
			typedef typename Container::value_type      	                   value_type;
			typedef typename Container::size_type                           size_type;

		/*
		=========================================================================
		Constructors, destructor, operator=
		=========================================================================
		*/
			// Stack() {}

			explicit Stack (const container_type& ctnr = container_type())
			: c(ctnr) {}

			Stack(const Stack& other) { c = other.c; };

			~Stack() {}

			Stack& operator=( const Stack& other ) {
				c = other.c;
				return *this;
			}

		/*
		=========================================================================
		Element access
		=========================================================================
		*/

			value_type& top() { return c.back(); }

			const value_type& top() const { return c.back(); }

		/*
		=========================================================================
		Capacity
		=========================================================================
		*/

			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }

		/*
		=========================================================================
		Modifiers
		=========================================================================
		*/
			void push (const value_type& val) { c.push_back(val); }
			void pop() { c.pop_back(); }

		/*
		=========================================================================
		Non-member functions (comparison operators + swap)
		=========================================================================
		*/
		
			friend bool operator==(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs) {
				return lhs.c == rhs.c;
			}

			friend bool operator!=(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs) {
				return lhs.c != rhs.c;
			}

			friend bool operator<(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs) {
				return lhs.c < rhs.c;
			}

			friend bool operator<=(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs) {
				return lhs.c <= rhs.c;
			}

			friend bool operator>(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs) {
				return lhs.c > rhs.c;
			}

			friend bool operator>=(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs) {
				return lhs.c >= rhs.c;
			}

		protected:
			container_type c;
	};
} // namespace ft

#endif
