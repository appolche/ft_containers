#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include "./Node.hpp"
#include "./RBTree.hpp"
#include "./Iterator.hpp"

namespace ft {
	template <typename T>
	class rbtree_iterator{
	public:
		typedef T                                                   value_type;
		typedef Node<value_type>                                    node_type;
		typedef size_t                                              difference_type;
		typedef value_type&                                         reference;
		typedef value_type*                                         pointer;
		typedef typename std::bidirectional_iterator_tag            iterator_category;

		rbtree_iterator() {
			root_ = NULL;
			base_ = NULL;
		}

		rbtree_iterator(const rbtree_iterator& rhs) {
			root_ = rhs.root_;
			base_ = rhs.base_;
		}

		rbtree_iterator(node_type* base, node_type* root) {
			root_ = root;
			base_ = base;
		}

		~rbtree_iterator(){}

		rbtree_iterator& operator=(const rbtree_iterator& rhs) {
			root_ = rhs.root_;
			base_ = rhs.base_;

			return *this;
		}

		bool operator==(const rbtree_iterator& rhs) {
			return base_ == rhs.base_;
		}

		bool operator!=(const rbtree_iterator& rhs) {
			return !(*this == rhs);
		}
 
		node_type* base() const {
			return base_;
		}

		reference operator*() const {
			if (base_ == NULL) {
					return max_()->value;
			}
			return base_->value;
		}

		pointer operator->() const {
			if (base_ == NULL) {
					return &max_()->value;
			}
			return &base_->value;
		}
		
		rbtree_iterator& operator++() {
			if (!base_) {
				return *this;
			}

			if (base_->right) {
					base_ = base_->right;
					while (base_->left) base_ = base_->left;
					return *this;
			}
			while (base_->parent && base_ == base_->parent->right) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return *this;
		}

		rbtree_iterator& operator--() {
			if (!base_) {
					base_ = max_();
					return *this;
			}

			if (base_->left) {
					base_ = base_->left;
					while (base_->right) base_ = base_->right;
					return *this;
			}
			while (base_->parent && base_ == base_->parent->left) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return *this;
		}
		rbtree_iterator operator++(int) {
			rbtree_iterator tmp = *this;
			if (!base_) {
				return tmp;
			}
			if (base_->right) {
					base_ = base_->right;
					while (base_->left) {
						base_ = base_->left;
					}
					return tmp;
			}
			while (base_->parent && base_ == base_->parent->right) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return tmp;
		}

		rbtree_iterator operator--(int) {
			rbtree_iterator tmp = *this;
			if (!base_) {
					base_ = max_();
					return tmp;
			}
			
			if (base_->left) {
					base_ = base_->left;
					while (base_->right) {
						base_ = base_->right;
					}
					return tmp;
			}
			while (base_->parent && base_ == base_->parent->left) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return tmp;
		}

	private:
		node_type* root_;
		node_type* base_;

		node_type* max_() const {
			if (root_ == NULL) {
				return NULL;
			}
			node_type* ptr = root_;
			while (ptr->right) {
					ptr = ptr->right;
			}

			return ptr;
		}

	}; // rbtree_iterator

	template <typename T>
	class rbtree_reverse_iterator{
	public:
		typedef T                                                   value_type;
		typedef Node<value_type>                                    node_type;
		typedef size_t                                              difference_type;
		typedef value_type&                                         reference;
		typedef value_type*                                         pointer;
		typedef typename std::bidirectional_iterator_tag            iterator_category;

		rbtree_reverse_iterator() {
			root_ = NULL;
			base_ = NULL;
		}

		rbtree_reverse_iterator(const rbtree_reverse_iterator& rhs) {
			root_ = rhs.root_;
			base_ = rhs.base_;
		}
		
		rbtree_reverse_iterator(node_type* base, node_type* root) {
			root_ = root;
			base_ = base;
		}

		~rbtree_reverse_iterator() {}

		rbtree_reverse_iterator& operator=(const rbtree_reverse_iterator& rhs) {
			root_ = rhs.root_;
			base_ = rhs.base_;

			return *this;
		}
		bool operator==(const rbtree_reverse_iterator& rhs) {
			return base_ == rhs.base_;
		}
		bool operator!=(const rbtree_reverse_iterator& rhs) {
			return !(*this == rhs);
		}

		node_type* base() const {
			return base_;
		}

		reference operator*() const {
			if (base_ == NULL) {
					return min_()->value;
			}

			return base_->value;
		}

		pointer operator->() const {
			if (base_ == NULL) {
					return &min_()->value;
			}

			return &base_->value;
		}

		rbtree_reverse_iterator& operator--() {
			if (!base_) {
					base_ = min_();
					return *this;
			}

			if (base_->right) {
					base_ = base_->right;
					while (base_->left) base_ = base_->left;
					return *this;
			}
			while (base_->parent && base_ == base_->parent->right) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return *this;
		}

		rbtree_reverse_iterator& operator++() {
			if (!base_) {
				return *this;
			}
			if (base_->left) {
					base_ = base_->left;
					while (base_->right) {
						base_ = base_->right;
					}
					return *this;
			}
			while (base_->parent && base_ == base_->parent->left) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return *this;
		}

		rbtree_reverse_iterator operator--(int) {
			rbtree_reverse_iterator tmp = *this;
			if (!base_) {
					base_ = min_();
					return tmp;
			}

			if (base_->right) {
					base_ = base_->right;
					while (base_->left) {
						base_ = base_->left;
					}
					return tmp;
			}
			while (base_->parent && base_ == base_->parent->right) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return tmp;
		}

		rbtree_reverse_iterator operator++(int) {
			rbtree_reverse_iterator tmp = *this;
			if (!base_) {
				return tmp;
			}
			if (base_->left) {
					base_ = base_->left;
					while (base_->right) {
						base_ = base_->right;
					}
					return tmp;
			}
			while (base_->parent && base_ == base_->parent->left) {
				base_ = base_->parent;
			}
			base_ = base_->parent;

			return tmp;
		}

	private:
		node_type* root_;
		node_type* base_;

		node_type* min_() const {
			if (!root_ ) {
				return NULL;
			}
			node_type* ptr = root_;
			while (ptr->left) {
					ptr = ptr->left;
			}
			
			return ptr;
		}

	}; // rbtree_reverse_iterator
}

#endif
