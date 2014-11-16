#ifndef BST_H_
#define BST_H_
#include <iterator>
#include <iostream>

template<typename T>
class BinarySearchTree {
    public:
        class Node {
            public:
                T data_;
                int size_;
                Node *left_, *right_;
                Node() {
                    left_ = nullptr;
                    right_ = nullptr;
                    size_ = 0;
                }

                Node(T data_) : Node() {
                    this->data_ = data_;
                    size_ = 1;
                }
        };

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
            return min(root_);
        }

        T* max() {
            return max(root_);
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

    private:
        Node* root_;

        Node* deleteMin(Node* node) {
            if (!node) { return nullptr; }
            if (node->left_) {
                node->left_ = deleteMin(node->left_);
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

        T* min(Node* node) {
            if (!node) { return nullptr; }
            if (!node->left_) {
                return &node->data_;
            } else {
                return min(node->left_);
            }
        }

        T* max(Node* node) {
            if (!node) { return nullptr; }
            if (!node->right_) {
                return &node->data_;
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

            if (e == node->data_) {
                return node;
            }

            if (e < node->data_) {
                node->left_ = insert(node->left_, e);
                node->size_ = size(node->left_) + size(node->right_) + 1;
            } else {
                node->right_ = insert(node->right_, e);
                node->size_ = size(node->left_) + size(node->right_) + 1;
            }

            return node;
        }

        void dfs(Node* node)
        {
            if (node == nullptr) {
                return;
            }

            dfs(node->left_);
            std::cout << node->data_ << "\n";
            dfs(node->right_);
        }
};
#endif
