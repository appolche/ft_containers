#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>

#include "./Pair.hpp"
#include "./Node.hpp"
#include "./Iterator.hpp"
#include "./RBTree_iterator.hpp"

// #define RED true
// #define BLACK false

namespace ft {
	// template< typename T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	// class RBTree;

	template <typename T, class Compare, class Allocator>
	class RBTree {
		public:
			typedef size_t																	size_type;
			typedef T																		value_type;
			typedef Node<T>																node_type;
			typedef node_type																*node_ptr;
			typedef typename Allocator::template rebind<node_type>::other	node_alloc_type;

			typedef rbtree_iterator<value_type>										iterator;
			typedef rbtree_iterator<value_type>										const_iterator;
			typedef rbtree_reverse_iterator<value_type>							reverse_iterator;
			typedef rbtree_reverse_iterator<value_type>							const_reverse_iterator;

			RBTree(const node_alloc_type& allocator = node_alloc_type()) : _alloc(allocator) {
				_root = NULL;
				_size = 0;
			}

			RBTree(const RBTree& rhs) {
				_root = _copyNode(rhs._root);
				_size = rhs._size;
				_alloc = rhs._alloc;
			}

			template <class InputIt>
			RBTree(InputIt first, InputIt last) {
				_root = NULL;
				_size = 0;
				insert(first, last);
			}

			~RBTree() {
				_deleteTree(_root);
			}

			RBTree &operator=(const RBTree& rhs) {
				_root = _copyNode(rhs._root);
				_size = rhs._size;
				_alloc = rhs._alloc;

				return *this;
			}

			node_alloc_type get_allocator() const {
				return _alloc;
			}

			iterator begin() { return iterator(min(_root), _root); }
			const_iterator begin() const { return const_iterator(min(_root), _root); }

			iterator end() { return iterator(NULL, _root); }
			const_iterator end() const { return const_iterator(NULL, _root); }

			reverse_iterator rbegin() { return reverse_iterator(max(_root), _root); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(max(_root), _root); }

			reverse_iterator rend() { return reverse_iterator(NULL, _root); }
			const_reverse_iterator rend() const { return reverse_iterator(NULL, _root); }

			bool empty() const { return _size == 0; }

			size_type size() const { return _size; }

			size_type max_size() const { return _alloc.max_size(); }

			void clear() {
				_deleteTree(_root);
				_root = NULL;
				_size = 0;
			}

			ft::pair<iterator, bool> insert(const value_type &value) {
				node_ptr elem = _alloc.allocate(1);
				_alloc.construct(elem, value);
				// make_root
				if (_root == NULL) {
					_root = elem;
					_size++;
					return ft::make_pair(iterator(elem, _root), true);
				}

				// search where to insert out new node
				node_ptr ptr = _root;
				node_ptr tmp = _root;
				while (tmp) {
					ptr = tmp;
					if (!Compare()(elem->value, ptr->value) && !Compare()(ptr->value, elem->value)) {
						_alloc.destroy(elem);
						_alloc.deallocate(elem, 0);
						return ft::make_pair(end(), false);
					} else if (Compare()(elem->value, ptr->value)) {
						tmp = ptr->left;
					} else {
						tmp = ptr->right;
					}
				}
				// inserting
				elem->color = RED;
				elem->parent = ptr;
				if (Compare()(elem->value, ptr->value)) {
					ptr->left = elem;
				} else {
					ptr->right = elem;
				}
				_balance_after_insert(elem);
				_size++;
				return ft::make_pair(iterator(elem, _root), true);
			}
			
			iterator insert(iterator, const value_type &value) {
				return insert(value).first;
			}

			template <class InputIt>
			void insert(InputIt first, InputIt last) {
				for (; first != last; first++) {
					insert(*first);
				}
			}

			void erase(iterator iter) {
				node_ptr z = iter.base();
				if (!z || !_size)
					return;

				node_ptr to_delete = z;
				node_ptr x = NULL;
				node_ptr y = z;
				bool y_orig_color = z->color;

				if (z->left == NULL) {
					x = z->right;
					_transplant(z, z->right);
				} else if (z->right == NULL) {
					x = z->left;
					_transplant(z, z->left);
				} else {
					y = min(z->right);
					y_orig_color = y->color;
					x = y->right;
					if (y->parent != z) {
						_transplant(y, y->right);
						y->right = z->right;
						z->right->parent = y;
					}
					_transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				if (y_orig_color == BLACK) {
					_balance_after_erase(x);
				}

				_alloc.destroy(to_delete);
				_alloc.deallocate(to_delete, 0);
				_size--;

				if (_size == 0) {
					_root = NULL;
				}
			}

			void erase(iterator first, iterator last) {
				for (; first != last; first++) {
					erase(first);
				}
			}

			size_type erase(const value_type &value) {
				iterator iter = find(value);
				if (iter == end()) {
					return 0;
				}
				erase(iter);
				return 1;
			}

			size_type count(const value_type &value) const {
				return (find(value) == end()) ? 0 : 1;
			}

			iterator find(const value_type &value) {
				if (!_root) {
					return end();
				}

				node_type elem(value);
				node_ptr ptr = _root;
				while (ptr) {
					if (!Compare()(elem.value, ptr->value) && !Compare()(ptr->value, elem.value)) {
						return iterator(ptr, _root);
					}
					if (Compare()(elem.value, ptr->value)) {
						ptr = ptr->left;
					} else {
						ptr = ptr->right;
					}
				}

				return (ptr) ? iterator(ptr, _root) : end();
			}

			const_iterator find(const value_type &value) const {
				if (!_root) {
					return end();
				}

				node_type elem(value);
				node_ptr ptr = _root;
				while (ptr) {
					if (!Compare()(elem.value, ptr->value) && !Compare()(ptr->value, elem.value)) {
						return const_iterator(ptr, _root);
					}
					if (Compare()(elem.value, ptr->value)) {
						ptr = ptr->left;
					} else {
						ptr = ptr->right;
					}
				}

				return (ptr) ? const_iterator(ptr, _root) : end();
			}

			ft::pair<iterator, iterator> equal_range(const value_type &value) {
				return ft::pair<iterator, iterator>(lower_bound(value), upper_bound(value));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const value_type &value) const {
				return ft::pair<const_iterator, const_iterator>(lower_bound(value), upper_bound(value));
			}

			iterator lower_bound(const value_type &value) {
				if (!_root) {
					return end();
				}

				for (iterator iter = begin(); iter != end(); iter++) {
					if (!Compare()(*iter, value)) {
						return iter;
					}
				}

				return end();
			}

			const_iterator lower_bound(const value_type &value) const {
				if (!_root) {
					return end();
				}
				
				for (const_iterator iter = begin(); iter != end(); iter++) {
					if (!Compare()(*iter, value)) {
						return iter;
					}
				}

				return end();
			}

			iterator upper_bound(const value_type &value) {
				if (!_root) {
					return end();
				}

				for (iterator iter = begin(); iter != end(); iter++) {
					if (Compare()(value, *iter) && !(!Compare()(value, *iter) && !Compare()(*iter, value))) {
						return iter;
					}
				}

				return end();
			}

			const_iterator upper_bound(const value_type &value) const {
				if (!_root) {
					return end();
				}

				for (const_iterator iter = begin(); iter != end(); iter++) {
					if (Compare()(value, *iter) && !(!Compare()(value, *iter) && !Compare()(*iter, value))) {
						return iter;
					}
				}

				return end();
			}

			node_ptr root() const { return _root; }

			node_ptr min(node_ptr ptr) const {
				if (!ptr) {
					return NULL;
				}

				while (ptr->left) {
					ptr = ptr->left;
				}

				return ptr;
			}

			node_ptr max(node_ptr ptr) const {
				if (!ptr) {
					return NULL;
				}

				while (ptr->right) {
					ptr = ptr->right;
				}

				return ptr;
			}

		private:
			node_ptr _copyNode(node_ptr rhs, node_ptr parent = NULL) {
				if (rhs == NULL) {
					return NULL;
				}

				node_ptr newNode = _alloc.allocate(1);
				_alloc.construct(newNode, rhs->value);

				newNode->color = rhs->color;
				newNode->parent = parent;
				newNode->left = _copyNode(rhs->left, newNode);
				newNode->right = _copyNode(rhs->right, newNode);

				return newNode;
			}

			void _transplant(node_ptr u, node_ptr v) {
				if (u->parent == NULL) {
					_root = v;
				} else if (u == u->parent->left) {
					u->parent->left = v;
				} else {
					u->parent->right = v;
				}

				if (v) {
					v->parent = u->parent;
				}
			}

			void _balance_after_erase(node_ptr x) {
				if (!x) {
					return;
				}

				while (x != _root && x->color == BLACK) {
					if (x == x->parent->left) {
						node_ptr w = x->parent->right;
						if (w->color == RED) {
							w->color = BLACK;
							x->parent->color = RED;
							_rotate_left(x->parent);
							w = x->parent->right;
						}
						if (w->left->color == BLACK && w->right->color == BLACK) {
							w->color = RED;
							x = x->parent;
						} else {
							if (w->right->color == BLACK)
							{
								w->left->color = BLACK;
								w->color = RED;
								_rotate_right(w);
								w = x->parent->right;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							_rotate_left(x->parent);
							x = _root;
						}
					} else {
						node_ptr w = x->parent->left;
						if (w->color == RED) {
							w->color = BLACK;
							x->parent->color = RED;
							_rotate_right(x->parent);
							w = x->parent->left; }
						if (w->left->color == BLACK && w->right->color == BLACK) {
							w->color = RED;
							x = x->parent;
						} else {
							if (w->left->color == BLACK) {
								w->right->color = BLACK;
								w->color = RED;
								_rotate_left(w);
								w = x->parent->left;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							_rotate_right(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK;
			}

			void _rotate_left(node_ptr X) {
				if (!X || !X->right) {
					return;
				}

				node_ptr Y = X->right;
				node_ptr *X_from_parent;
				node_ptr parent = X->parent;
				if (!parent) {
					X_from_parent = NULL;
				} else {
					X_from_parent = (X == parent->left) ? &parent->left : &parent->right;
				}

				node_ptr a = X->left;
				node_ptr b = Y->left;
				node_ptr c = Y->right;

				if (parent) {
					*X_from_parent = Y;
				} else {
					_root = Y;
				}
				Y->parent = parent;
				X->parent = Y;
				Y->left = X;
				Y->right = c;
				X->left = a;
				X->right = b;
				if (b) {
					b->parent = X;
				}
			}

			void _rotate_right(node_ptr Y) {
				if (!Y || !Y->left) {
					return;
				}

				node_ptr X = Y->left;
				node_ptr *Y_from_parent;
				node_ptr parent = Y->parent;
				if (!parent) {
					Y_from_parent = NULL;
				} else {
					Y_from_parent = (Y == parent->left) ? &parent->left : &parent->right;
				}

				node_ptr a = X->left;
				node_ptr b = X->right;
				node_ptr c = Y->right;

				if (parent) {
					*Y_from_parent = X;
				} else {
					_root = X;
				}
				X->parent = parent;
				Y->parent = X;
				X->right = Y;
				X->left = a;
				Y->left = b;
				Y->right = c;
				if (b) {
					b->parent = Y;
				}
			}

			void _balance_after_insert(node_ptr elem) {
				if (!elem || !elem->parent || !elem->parent->parent)
					return;

				node_ptr parent = elem->parent;
				node_ptr grandParent = elem->parent->parent;

				// if (elem->color == RED && parent->color == RED) {
				// 	rotate();
				// 	color_check();
				// } else {
				// 	color_flip();
				// }

				while (elem != _root && parent->color == RED) {
					if (parent == grandParent->left) {
						node_ptr aunt = grandParent->right;

						if (aunt && aunt->color == RED) {
							parent->color = BLACK;
							aunt->color = BLACK;
							grandParent->color = RED;
							elem = grandParent;
						} else {
							if (elem == parent->right) {
								elem = parent;
								_rotate_left(elem);
							}
							parent->color = BLACK;
							grandParent->color = RED;
							_rotate_right(grandParent);
						}
					} else {
						node_ptr aunt = grandParent->left;

						if (aunt && aunt->color == RED) {
							parent->color = BLACK;
							aunt->color = BLACK;
							grandParent->color = RED;
							elem = grandParent;
						} else {
							if (elem == parent->left) {
								elem = parent;
								_rotate_right(elem);
							}
							parent->color = BLACK;
							grandParent->color = RED;
							_rotate_left(grandParent);
						}
					}
				}
				_root->color = BLACK;
			}

			void _deleteTree(node_ptr node) {
				if (!node) {
					return;
				}

				_deleteTree(node->left);
				_deleteTree(node->right);

				_alloc.destroy(node);
				_alloc.deallocate(node, 0);
			}

			size_type			_size;
			node_ptr				_root;
			node_alloc_type	_alloc;
	};

}

#endif
