#ifndef MESA_CISC187_BINARY_SEARCH_TREE_H
#define MESA_CISC187_BINARY_SEARCH_TREE_H

// 
// Binary Search Tree
// Dave Parillo: 20190521
//

#include <cstddef>
#include <iterator>
#include <ostream>
#include <iostream>

#include "tree_node.h"

namespace mesa {

    template <typename T>
    struct tree_iterator {
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

        tree_iterator() = default;
        tree_iterator(const tree::tree_node<T>* n)
            : node{ n }
        { }

        constexpr
            const T& operator*() const noexcept {
            return node->value;
        }

        //prefix increment
        // move to the next largest value
        tree_iterator& operator++() {
            if (node == nullptr) return *this;

            if (node->right != nullptr) {
                // find the smallest node on the right subtree
                node = mesa::tree::min_element(node->right);
            }
            else {
                // finished with right subtree and there is no right
                // search up for first parent with a non-null right child
                // or nullptr,
                auto parent = node->parent;
                while (parent != nullptr && node == parent->right) {
                    node = parent;
                    parent = parent->parent;
                }
                node = parent;
            }
            return *this;
        }

        //postfix increment
        const tree_iterator operator++(int) {
            tree_iterator tmp(*this);
            ++* this;
            return tmp;
        }
        //prefix INCREMENT - change iterators pointer to point to the next treenode in an in-order traversal
        //prefix decrement - iterator should point to inorder predecessor //finding predecessor - https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
        const tree_iterator& operator--() {
            if (node == nullptr) return *this;

            if (node->left != nullptr) {
                // find right most child of left subtree (largest child of the left tree)
                node = mesa::tree::max_element(node->left);
            }
            else {
                //if left subtree is null, find the first parent with a non null left child or nullptr
                auto parent = node->parent;
                while (parent != nullptr && node == parent->left) {
                    node = parent;
                    parent = parent->parent;
                }
                node = parent;
            }
            return *this;
        }

        //postfix decrement
        const tree_iterator operator--(int) {
            tree_iterator tmp(*this);
            --* this;
            return tmp;
        }

        const tree::tree_node<T>* node;
    };

} // end namespace mesa

// Regular
template <class T>
inline
bool operator==(const mesa::tree_iterator<T>& lhs, const mesa::tree_iterator<T>& rhs) {
    return lhs.node == rhs.node;
}
template <class T>
inline
bool operator!=(const mesa::tree_iterator<T>& lhs, const mesa::tree_iterator<T>& rhs) {
    return !(lhs == rhs);
}




namespace mesa {

    // a binary search tree
    template<class T>
    class bstree {
    public:
        using value_type = T;
        using const_iterator = const tree_iterator<T>;
        using iterator = const_iterator;
        using reverse_iterator = const_iterator;
        using const_reverse_iterator = const_iterator;

        bstree() = default;
        explicit
            bstree(const T& value)
            : root{ new tree::tree_node<T>{value} }
        { }

        // copy construct and assign
        bstree(const bstree& other) {
            root = mesa::tree::deep_copy(other.root);
        }
        bstree& operator=(const bstree& other) {
            bstree copy = other;
            std::swap(*this, copy);
            return *this;
        }

        // move construct and assign
        bstree(bstree&& other)
            : root{ other.root }
        {
            other.root = nullptr;
        }
        bstree& operator=(const bstree&& other) {
            std::swap(root, other.root);
            return *this;
        }

        ~bstree() {
            mesa::tree::erase(root);
        }

        /**
         * Remove all elements from tree.
         */
        void erase() {
            mesa::tree::erase(root);
        }
        /**
         * Remove one value from a tree.
         */
        void erase(const T& value) {
            mesa::tree::erase(value, root);
        }

        constexpr
            bool empty() const noexcept { return root == nullptr; }

        bool contains(const T& value) const noexcept
        {
            return mesa::tree::contains(value, root);
        }

        /**
         * Find a value in tree
         */
        const_iterator find(const T& value) const noexcept {
            return mesa::tree::find(value, root);
        }

        /**
         * Insert a new value in tree
         */
        const_iterator insert(const T& val) {
            return const_iterator(insert(val, root, nullptr));
        }

        const_iterator begin() noexcept {
            if (root->left != nullptr) {
                return mesa::tree::min_element(root);
            }
            return root;
        }

        const_iterator end() noexcept {
            return root;
        }

        const_iterator rbegin() noexcept {
            if (root->right != nullptr) {
                return mesa::tree::max_element(root);
            }
            return root;
        }

        const_iterator rend() noexcept {
            return root;
        }


    private:
        tree::tree_node<T>* root = nullptr;

        /**
         * Insert a new value in the tree.
         * Duplicates are overwritten with the new value.
         */
        tree::tree_node<T>*
            insert(const T& value, tree::tree_node<T>*& node, tree::tree_node<T>* parent) {
            if (node == nullptr) {
                node = new tree::tree_node<T>(value, nullptr, nullptr, parent); // need 4 parameters. value, left child, right child, parent
                return node;
            }
            if (value < node->value) {
                return insert(value, node->left, node);
            } if (node->value < value) {
                return insert(value, node->right, node);
            }
            node->value = value;
            return node;
        }

        // write a tree to an output stream
        friend
            std::ostream& operator<< (std::ostream& os, const bstree& node) {
            return os << node.root;
        }

    };


} // end namespace mesa

#endif


