#ifndef NODE_HPP
#define NODE_HPP

#define RED		true
#define BLACK	false

namespace ft {
	template<typename T>
	struct Node{
		Node() : value(T()), color(RED), left(NULL), right(NULL), parent(NULL) {}

		Node(const T& value) : value(value), color(RED), 
		left(NULL), right(NULL), parent(NULL) {}

		Node(const Node& rhs) 
		: value(rhs.value), color(rhs.color), 
		left(rhs.left), right(rhs.right), parent(rhs.parent) {}

		Node(Node* left, Node* right, Node* parent, const T& value, bool color)
		: left(left), right(right), parent(parent), value(value), color(color) {}

		~Node() {}

		Node& operator=(const Node& rhs) {
			if (this != rhs) {
				value = rhs.value;
				color = rhs.color;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
			}
			return *this;
		}

		T		value;
		bool	color;
		Node*	left;
		Node*	right;
		Node*	parent;
	};  // NODE
}

#endif