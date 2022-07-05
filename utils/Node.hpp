#ifndef NODE_HPP
#define NODE_HPP

// #define RED true
// #define BLACK false

namespace ft {

	enum Color{
		RED,
		BLACK
	};

	template<typename T>
	struct Node{
		Node() : value(T()), color(RED), left(NULL), right(NULL), parent(NULL) {

		}
		Node(const T& value) : value(value), color(RED),
										left(NULL), right(NULL), parent(NULL) {

		}
		Node(const Node& another) 
			: value(another.value), color(another.color),
					left(another.left), right(another.right), parent(another.parent) {
			
		}
		Node(Node* left, Node* right, Node* parent, const T& value, Color color)
			: left(left), right(right), parent(parent), value(value), color(color) {
			
		}
		~Node(){

		}

		Node& operator=(const Node& another){
			value = another.value;
			color = another.color;
			left = another.left;
			right = another.right;
			parent = another.parent;

			return *this;
		}

		T value;
		Color color;
		Node* left;
		Node* right;
		Node* parent;
	};  // NODE
}

#endif