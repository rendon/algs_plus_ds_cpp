#ifndef BST_H_
#define BST_H_
#include <iterator>
#include <iostream>

template<typename T>
class BinarySearchTree {
    public:
        class Node {
            public:
                T data;
                Node *left, *right;
                Node()
                {
                    left = nullptr;
                    right = nullptr;
                }

                Node(T data) : Node()
                {
                    this->data = data;
                }
        };

        BinarySearchTree()
        {
            root = nullptr;
        }

        Node* insert(T data)
        {
            if (root == nullptr) {
                return root = new Node(data);
            } else {
                return insert(root, data);
            }
        }

        void print()
        {
            dfs(root);
        }

    private:
        Node *root;

        Node* insert(Node *node, T data)
        {
            if (data == node->data) {
                return node;
            } else if (data < node->data) {
                if (node->left == nullptr) {
                    return node->left = new Node(data);
                } else {
                    return insert(node->left, data);
                }
            } else {
                if (node->right == nullptr) {
                    return node->right = new Node(data);
                } else {
                    return insert(node->right, data);
                }
            }
        }

        void dfs(Node *node)
        {
            if (node == nullptr) {
                return;
            }

            dfs(node->left);
            std::cout << node->data << "\n";
            dfs(node->right);
        }
};
#endif
