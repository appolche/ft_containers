#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>

namespace ft {
	template <typename T1, typename T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type; 

		pair() : first(first_type()), second(second_type()) {}

		pair(const first_type& first, const second_type& second) : first(first), second(second) {}

		template <class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

		pair(const pair& p) : first(p.first), second(p.second) {}

		~pair() {}

		pair& operator=(const pair& other) {
			first = other.first;
			second = other.second;
			return *this;
		}

		first_type first;
		second_type second;
	};

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 t, T2 u) {
		return pair<T1, T2>(t, u);
	}

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return lhs.first < rhs.first || (lhs.first <= rhs.first && lhs.second < rhs.second);
	}

	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(rhs < lhs);
	}

	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return rhs < lhs;
	}

	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}

} // namespace ft

#endif
