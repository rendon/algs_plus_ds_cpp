#ifndef BST_H_
#define BST_H_
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class BinarySearchTree {
    public:
        class Node {
            public:
                T data_;
                int size_;
                Node *left_, *right_, *parent_;
                Node() {
                    left_ = nullptr;
                    right_ = nullptr;
                    parent_ = nullptr;
                    size_ = 0;
                }

                Node(T data_) : Node() {
                    this->data_ = data_;
                    size_ = 1;
                }
        };

        class iterator : std::iterator<std::input_iterator_tag, T> {
            private:
                BinarySearchTree* bst_;
                Node* ptr_;
                Node* last_;
                void next() {
                    if (!last_) {
                        ptr_ = nullptr;
                        return;
                    }
                    Node* prev = nullptr;
                    while (ptr_ && (!ptr_->right_ || ptr_->right_ == prev)) {
                        prev = ptr_;
                        ptr_ = ptr_->parent_;
                    }
                    ptr_ = bst_->min(ptr_->right_);

                    if (ptr_ == last_) {
                        last_ = nullptr;
                    }
                }
            public:
                iterator() { 
                    bst_ = nullptr;
                }

                iterator(BinarySearchTree* bst, Node *node) {
                    bst_ = bst;
                    ptr_ = bst_->min(node);
                    last_ = bst_->max(node);
                }

                iterator& operator=(const iterator& that) {
                    ptr_ = that.ptr_;
                    bst_ = that.bst_;
                    last_ = that.last_;
                    return *this;
                }

                iterator& operator++() {
                    next();
                    return *this;
                }

                iterator operator++(int) {
                    iterator temp = *this;
                    next();
                    return temp;
                }

                bool operator !=(const iterator& that) const {
                    return ptr_ != that.ptr_;
                }

                T& operator*() {
                    return ptr_->data_;
                }

        };

        iterator begin() {
            return iterator(this, root_);
        }

        iterator end() {
            return iterator(this, nullptr);
        }

        ~BinarySearchTree() {
            clear(root_);
        }

        BinarySearchTree() {
            root_ = nullptr;
        }

        Node* insert(T data_) {
            if (root_ == nullptr) {
                return root_ = new Node(data_);
            } else {
                return insert(root_, data_);
            }
        }

        void print() {
            dfs(root_);
        }

        int size() {
            return size(root_);
        }

        T* find(const T& e) {
            return find(root_, e);
        }

        T* floor(const T& e) {
            return floor(root_, e);
        }

        T* ceiling(const T& e) {
            return ceiling(root_, e);
        }

        T* min() {
            if (!root_) { return nullptr; }
            return &min(root_)->data_;
        }

        T* max() {
            if (!root_) { return nullptr; }
            return &max(root_)->data_;
        }

        int rank(const T& e) {
            return rank(root_, e);
        }

        T* select(int k) {
            return select(root_, k);
        }

        void deleteMin() {
            root_ = deleteMin(root_);
        }

        void deleteMax() {
            deleteMax(root_);
        }

        void clear() {
            clear(root_);
        }

        void erase(const T& key) {
            erase(root_, key);
        }

        vector<const T*> range(const T& low, const T& high) {
            vector<const T*> values;
            range(root_, low, high, values);
            return values;
        }

    private:
        Node* root_;

        void range(Node *node, const T& low, const T& high, vector<const T*>& V) {
            if (!node) { return; }
            if (low < node->data_) {
                range(node->left_, low, high, V);
            }

            if (low <= node->data_ && node->data_ <= high) {
                V.push_back(&node->data_);
            }

            if (node->data_ < high) {
                range(node->right_, low, high, V);
            }
        }

        Node* unlinkMin(Node *node) {
            if (!node) { return nullptr; }
            if (node->left_) {
                node->left_ = unlinkMin(node->left_);
                if (node->left_) {
                    node->left_->parent_ = node;
                }
                node->size_ = size(node->right_) + size(node->left_) + 1;
                return node;
            }

            return node->right_;
        }

        /* Hibbard method to delete nodes from a BST.*/
        Node* erase(Node* node, const T& key) {
            if (!node) { return nullptr; }
            if (key < node->data_) {
                node->left_ = erase(node->left_, key);
            } else if (node->data_ < key) {
                node->right_ = erase(node->right_, key);
            } else {
                Node* t = node;
                node = min(node->right_);
                node->right_ = unlinkMin(t->right_);
                node->left_ = t->left_;
                delete t;
            }
            if (node->left_) {
                node->left_->parent_ = node;
            }
            if (node->right_) {
                node->right_->parent_ = node;
            }
            node->size_ = size(node->left_) + size(node->right_) + 1;
            return node;
        }


        Node* deleteMin(Node* node) {
            if (!node) { return nullptr; }
            if (node->left_) {
                node->left_ = deleteMin(node->left_);
                if (node->left_) {
                    node->left_->parent_ = node;
                }
                node->size_ = size(node->left_) + size(node->right_) + 1;
                return node;
            } else {
                Node* temp = node->right_;
                delete node;
                return temp;
            }
        }

        Node* deleteMax(Node* node) {
            if (!node) { return nullptr; }
            if (node->right_) {
                node->right_ = deleteMax(node->right_);
                if (node->right_) {
                    node->right_->parent_ = node;
                }
                node->size_ = size(node->left_) + size(node->right_) + 1;
                return node;
            } else {
                Node *temp = node->left_;
                delete node;
                return temp;
            }
        }

        int rank(Node* node, const T& e) {
            if (!node) { return 0; }
            if (e < node->data_) {
                return rank(node->left_, e);
            } else if (e > node->data_) {
                return  rank(node->right_, e) + size(node->left_) + 1;
            } else {
                return size(node->left_);
            }
        }

        T* select(Node* node, int k) {
            if (!node) { return nullptr; }
            int left_size = size(node->left_);
            if (k < left_size) {
                return select(node->left_, k);
            } else if (k > left_size) {
                return select(node->right_, k - left_size - 1);
            } else {
                return &node->data_;
            }
        }

        int size(Node* node) {
            if (!node) { return 0; }
            return node->size_;
        }

        Node* min(Node* node) {
            if (!node) { return nullptr; }
            if (!node->left_) {
                return node;
            } else {
                return min(node->left_);
            }
        }

        Node* max(Node* node) {
            if (!node) { return nullptr; }
            if (!node->right_) {
                return node;
            } else {
                return max(node->right_);
            }
        }

        T* floor(Node* node, const T& e) {
            if (!node) { return nullptr; }
            if (e < node->data_) {
                return floor(node->left_, e);
            } else {
                T* temp = floor(node->right_, e);
                if (!temp) {
                    return &node->data_;
                } else {
                    return temp;
                }
            }
        }

        T* ceiling(Node* node, const T& e) {
            if (!node) { return nullptr; }
            if (e > node->data_) {
                return ceiling(node->right_, e);
            } else {
                T* temp = ceiling(node->left_, e);
                if (!temp) {
                    return &node->data_;
                } else {
                    return temp;
                }
            }
        }


        T* find(Node* node, const T& e) {
            if (!node) { return nullptr; }
            if (e < node->data_) {
                return find(node->left_, e);
            } else if (e > node->data_) {
                return find(node->right_, e);
            } else {
                return &node->data_;
            }
        }

        Node* insert(Node* node, T e) {
            if (!node) {
                return new Node(e);
            }

            if (e < node->data_) {
                node->left_ = insert(node->left_, e);
                node->left_->parent_ = node;
            } else if (node->data_ < e) {
                node->right_ = insert(node->right_, e);
                node->right_->parent_ = node;
            }

            node->size_ = size(node->left_) + size(node->right_) + 1;
            return node;
        }

        void dfs(Node* node)
        {
            if (node == nullptr) {
                return;
            }

            dfs(node->left_);
            std::cout << node->data_ << " ";
            dfs(node->right_);
        }

        void clear(Node *node) {
            if (!node) { return; }
            if (node->left_) {
                clear(node->left_);
            }
            if (node->right_) {
                clear(node->right_);
            }
            delete node;
        }

};
#endif
