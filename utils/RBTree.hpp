#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>

#define RED true
#define BLACK false

template <typename T>
struct Node {
	// Node(T data)
	// : value(value), color(RED), parent(NULL), left(NULL), right(NULL) {};

	T			value;
	bool		color;
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
struct Node
{
	// public :
	// 	template <typename T, typename Compare, typename Allocator>
	// 	friend class Tree;

	// 	template <typename Key, typename T, typename Compare, typename Alloc>
	// 	friend class map;

	private :
		T			value;
		bool		color;
		Node<T>* parent;
		Node<T>* left;
		Node<T>* right;

	public :
		Node(const T& data = T())
			: value(value), color(RED), parent(NULL), left(NULL), right(NULL) {}

		Node(const Node& rhs)
			: value(rhs.value), color(rhs.color), parent(rhs.parent), left(rhs.left), right(rhs.right) {}

		Node& operator= (const Node& rhs)
		{
			this->value = rhs.value;
			this->color = rhs.color;
			this->parent = rhs.parent;
			this->left = rhs.left;
			this->right = rhs.right;
			return (*this);
		}

		~Node()
		{ }
};
 
template <typename T, typename Compare, typename Allocator>
class RBTree {

	public:
		typedef size_t																	size_type;
		typedef T																		value_type;
		typedef Node<value_type>													node;
		typedef Compare																key_compare;
		typedef Allocator																allocator_type;
		typedef typename allocator_type::template rebind<Node>::other	node_alloc_type;
		// typedef TreeIterator<value_type>				iterator;
		// typedef TreeReverseIterator<value_type>			reverse_iterator;
		// typedef TreeConstIterator<value_type>			const_iterator;
		// typedef TreeConstReverseIterator<value_type>	const_reverse_iterator;

	private:
			node_alloc_type	_alloc;
			node*					_root;
			size_type			_size;
			
	public:
		RBTree(const allocator_type& alloc = allocator_type())
			: _alloc(alloc) {
				_root = NULL;
				_size = 0;
			}

		RBTree(const RBTree& rhs) {
			_alloc = rhs._alloc;
			// _root = deep_copy
			_size = rhs._size;
		}

		

};

{
		Node* create_elem(T value) {
			Node* node = new Node;
			node->value = value;
			node->color = BLACK;
			node->parent = node;
			node->left = NULL; 
			node->right = NULL;
			return node;
		}

		void insert(Node parent, Node elem) {
			if (elem->value < parent->value) {
				if (parent->left == NULL) {
					 parent->left = elem;
				} else {
					insert(parent->left, elem);
				}
			} else {
				if (parent->right == NULL) {
					 parent->right = elem;
				} else {
					insert(parent->right, elem);
				}
			}
		}

		Node* findElem(Node* elem) {
			if (elem->left != NULL) {
				findElem(elem->left);]
			}
			return elem;
			if (elem->right != NULL) {
				findElem(elem->right);
			}
		}

		void printTree(Node* elem) {
			if (elem->left != NULL) {
				printTree(elem->left);
			}
			std::cout << "Value = " << elem->value << std::endl;
			if (elem->right != NULL) {]
				printTree(elem->right);
			}
		}

		void printReverseTree(Node* elem) {
			if (elem->right != NULL) {
				print(elem->right);
			}
			std::cout << "Value = " << elem->value << std::endl;
			if (elem->left != NULL) {
				print(elem->left);
			}
		}

};

template <typename T, typename Compare, bool isMulti>
class Tree
	{
	public :
		typedef T										value_type;
		typedef TreeNode<value_type>					node;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef TreeIterator<value_type>				iterator;
		typedef TreeReverseIterator<value_type>			reverse_iterator;
		typedef TreeConstIterator<value_type>			const_iterator;
		typedef TreeConstReverseIterator<value_type>	const_reverse_iterator;
		typedef size_t									size_type;
		typedef Compare									key_compare;

	protected :
		node*		_root;
		node*		_left;
		node*		_right;
		key_compare	cmp;
		size_type	_size;

		void remove()
		{
			iterator last = end();
			iterator curr = begin(), next;
			while (curr != last) {
				next = ++curr;
				--curr;
				erase(curr);
				curr = next;
			}
		}

		void rotateLeft(node* x)
		{
			node* y = x->_right;
			x->_right = y->_left; // set right as left grandson(left son of right son)
			if (y->_left != NULL)
				y->_left->_parent = x;
			if (y != NULL)
				y->_parent = x->_parent;
			if (x->_parent) { // make x child of y
				if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
			}
			else
				this->_root = y;
			y->_left = x;
			if (x != NULL) // set links(x is left y child)
				x->_parent = y;
		}

		void rotateRight(node* x)
		{
			node* y = x->_left;
			x->_left = y->_right;  // set right as right grandson(right son of left son)
			if (y->_right != NULL)
				y->_right->_parent = x;
			if (y != NULL)
				y->_parent = x->_parent;
			if (x->_parent) { // make x child of y
				if (x == x->_parent->_right)
					x->_parent->_right = y;
				else
					x->_parent->_left = y;
			}
			else
				this->_root = y;
			y->_right = x;
			if (x != NULL) // set links(x is right y child)
				x->_parent = y;
		}

		void insertFixup(node* x)
		{
			if (x == NULL)
				return ;
			while (x != this->_root && x->_parent->_color == YELLOW) {
				node* parent = x->_parent;
				node* grandParent = parent->_parent;
				if (parent == grandParent->_left) {
					node* uncle = grandParent->_right;
					if (uncle != NULL && uncle != this->_first &&
						uncle != this->_last && uncle->_color == YELLOW) {
						parent->_color = BLUE;
						uncle->_color = BLUE;
						grandParent->_color = YELLOW;
						x = grandParent;
					}
					else {
						if (x == parent->_right) {
							x = parent;
							rotateLeft(x);
						}
						x->_parent->_color = BLUE;
						x->_parent->_parent->_color = YELLOW;
						rotateRight(x->_parent->_parent);
					}
				}
				else if (parent == grandParent->_right) {
					node* uncle = grandParent->_left;
					if (uncle != NULL && uncle != this->_first &&
					    uncle != this->_last && uncle->_color == YELLOW) {
						parent->_color = BLUE;
						uncle->_color = BLUE;
						grandParent->_color = YELLOW;
						x = grandParent;
					}
					else {
						if (x == parent->_left) {
							x = parent;
							rotateRight(x);
						}
						x->_parent->_color = BLUE;
						x->_parent->_parent->_color = YELLOW;
						rotateLeft(x->_parent->_parent);
					}
				}
			}
			this->_root->_color = BLUE;
		}

		void transplant(node* x, node* y)
		{
			if (x != NULL && x->_parent == NULL)
				this->_root = y;
			else if (x == x->_parent->_left)
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			if (y != NULL)
				y->_parent = x->_parent;
		}

		void eraseFixup(node* x)
		{
			if (x == NULL)
				return ;
			while (x != this->_root && x->_color == BLUE) {
				if (x == x->_parent->_left) {
					node* y = x->_parent->_right;
					if (y->_color == YELLOW) {
						y->_color = BLUE;
						x->_parent->_color = YELLOW;
						rotateLeft(x->_parent);
						y = x->_parent->_right;
					}
					if (y->_left->_color == BLUE && y->_right->_color == BLUE) {
						y->_color = YELLOW;
						x = x->_parent;
					}
					else {
						if (y->_right->_color == BLUE) {
							y->_left->_color = BLUE;
							y->_color = YELLOW;
							rotateRight(y);
							y = x->_parent->_right;
						}
						y->_color = x->_parent->_color;
						x->_parent->_color = BLUE;
						y->_right->_color = BLUE;
						rotateLeft(x->_parent);
						x = this->_root;
					}
				}
				else {
					node* y = x->_parent->_left;
					if (y->_color == YELLOW) {
						y->_color = BLUE;
						x->_parent->_color = YELLOW;
						rotateRight(x->_parent);
						y = x->_parent->_left;
					}
					if (y->_right->_color == BLUE && y->_left->_color == BLUE) {
						y->_color = YELLOW;
						x = x->_parent;
					}
					else {
						if (y->_left->_color == BLUE) {
							y->_right->_color = BLUE;
							y->_color = YELLOW;
							rotateLeft(y);
							y = x->_parent->_left;
						}
						y->_color = x->_parent->_color;
						x->_parent->_color = BLUE;
						y->_left->_color = BLUE;
						rotateRight(x->_parent);
						x = this->_root;
					}
				}
			}
			x->_color = BLUE;
		}

		void traversal(node* x) const
		{
			if (x == NULL)
				return ;
			traversal(x->_left);
			traversal(x->_right);
			std::string color = x->_color == YELLOW ? "\e[33m" : "\e[34m";
			if (x != this->_first && x != this->_last)
				std::cout << "node: " << color << "[" << x->_data.first << "]" << "\e[0m" << "    addr: " << x << ", left: "
					<< x->_left << ", right: " << x->_right << ", parent: " << x->_parent << std::endl;
			else
				std::cout << "found limit node, with addr: " << x << std::endl;
		}

	public :
		explicit Tree(const key_compare& cmp = key_compare())
			: _root(NULL), _cmp(cmp), _size(0)
		{
			this->_first = new node();
			this->_last = new node();
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
		}

		Tree(const Tree& tree)
			: _root(NULL), _cmp(tree._cmp), _size(0)
		{
			this->_first = new node();
			this->_last = new node();
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
			insert(tree.begin(), tree.end());
		}

		Tree& operator= (const Tree& tree)
		{
			clear();
			delete this->_first;
			delete this->_last;
			this->_first = new node();
			this->_last = new node();
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
			this->_root = NULL;
			this->_cmp = tree._cmp;
			this->_size = 0;
			insert(tree.begin(), tree.end());
			return (*this);
		}

		virtual ~Tree()
		{
			clear();
			delete this->_first;
			delete this->_last;
		}

		iterator begin()
		{ return (iterator(this->_first->_parent)); }

		iterator end()
		{ return (iterator(this->_last)); }

		const_iterator begin() const
		{ return (const_iterator(this->_first->_parent)); }

		const_iterator end() const
		{ return (const_iterator(this->_last)); }

		reverse_iterator rbegin()
		{ return (reverse_iterator(this->_last->_parent)); }

		reverse_iterator rend()
		{ return (reverse_iterator(this->_first)); }

		const_reverse_iterator rbegin() const
		{ return (const_reverse_iterator(this->_last->_parent)); }

		const_reverse_iterator rend() const
		{ return (const_reverse_iterator(this->_first)); }

		virtual void clear()
		{
			remove();
			this->_first->_parent = this->_last;
			this->_last->_parent = this->_first;
		}

		size_type size() const
		{ return (this->_size); }

		std::pair<iterator, bool> insert(const value_type& val)
		{
			if (this->_size == 0) {
				this->_root = new node(val, NULL, this->_first, this->_last, BLUE);
				this->_first->_parent = this->_root;
				this->_size++;
				return (std::pair<iterator, bool>(iterator(this->_root), true));
			}

			node* x = this->_root;
			while (x != NULL) {
				if (this->_cmp(val, x->_data)) {
					if (x->_left != NULL && x->_left != this->_first)
						x = x->_left;
					else {
						node* item = new node(val, x, x->_left, NULL);
						if (x->_left != NULL)
							x->_left->_parent = item;
						x->_left = item;
						this->_size++;
						insertFixup(item);
						return (std::pair<iterator, bool>(iterator(item), true));
					}
				}
				else if ((!isMulti && this->_cmp(x->_data, val)) || (isMulti && !this->_cmp(val, x->_data))) {
					if (x->_right != NULL && x->_right != this->_last)
						x = x->_right;
					else {
						node* item = new node(val, x, NULL, x->_right);
						if (x->_right != NULL)
							x->_right->_parent = item;
						x->_right = item;
						this->_size++;
						insertFixup(item);
						return (std::pair<iterator, bool>(iterator(item), true));
					}
				}
				else
					return (std::pair<iterator, bool>(iterator(x), false));
			}
			return (std::pair<iterator, bool>(iterator(x), false));
		}

		virtual void erase(iterator it)
		{
			node* x = it._ptr;
			if (x == NULL || x == this->_first || x == this->_last)
				return;

			node* y = x;
			node* z;
			bool color = y->_color;

			if (x->_left == NULL) {
				z = x->_right;
				transplant(x, x->_right);
			}
			else if (x->_right == NULL) {
				z = x->_left;
				transplant(x, x->_left);
			}
			else {
				y = x->_right;
				while (y->_left != NULL)
					y = y->_left;
				color = y->_color;
				z = y->_right;
				if (y->_parent == x) {
					if (z != NULL)
						z->_parent = y;
				}
				else {
					transplant(y, y->_right);
					y->_right = x->_right;
					y->_right->_parent = y;
				}
				transplant(x, y);
				y->_left = x->_left;
				y->_left->_parent = y;
				y->_color = x->_color;
			}

			if (color == BLUE)
				eraseFixup(z);

			delete x;
			this->_size--;
		}

		iterator find(const value_type& data)
		{
			node* item = this->_root;
			while (item != NULL && item != this->_first && item != this->_last) {
				if (this->_cmp(data, item->_data))
					item = item->_left;
				else if (this->_cmp(item->_data, data))
					item = item->_right;
				else
					return (iterator(item));
			}
			return (end());
		}

		const_iterator find(const value_type& data) const
		{
			node* item = this->_root;
			while (item != NULL && item != this->_first && item != this->_last) {
				if (this->_cmp(data, item->_data))
					item = item->_left;
				else if (this->_cmp(item->_data, data))
					item = item->_right;
				else
					return (const_iterator(item));
			}
			return (end());
		}

		size_type count(const value_type& data) const
		{
			size_type result = 0;
			for (iterator it = begin(); it != end(); it++) {
				if (!this->_cmp(data, *it) && !this->_cmp(*it, data))
					result++;
			}
			return (result);
		}

		void swap(Tree& tree)
		{
			ft::swap(this->_root, tree._root);
			ft::swap(this->_first, tree._first);
			ft::swap(this->_last, tree._last);
			ft::swap(this->_cmp, tree._cmp);
			ft::swap(this->_size, tree._size);
		}

		void traversal() const
		{
			std::cout << "tree with size: " << this->_size << std::endl;
			traversal(this->_root);
		}

		Tree& getTree()
		{ return (*this); }
	};


#endif