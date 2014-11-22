#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_
#include <iterator>
#include <algorithm>
const bool RED = true;
const bool BLACK = false;
template <typename T>
class RedBlackTree {
public:
    RedBlackTree() {
        root_ = nullptr;
    }

    void insert(const T& data) {
        root_ = insert(root_, data);
        root_->color_ = BLACK;
    }

    void print() {
        print(root_);
    }

    int height() {
        return height(root_);
    }

    int size() {
        return size(root_);
    }

private:
    class Node {
    private:
        friend class RedBlackTree;
        friend class iterator;
        T data_;
        Node* left_;
        Node* parent_;
        Node* right_;
        bool color_;
        int size_;
        Node() {
            left_ = nullptr;
            parent_ = nullptr;
            right_ = nullptr;
            color_ = RED;
            size_ = 0;
        }

        Node(const T& data) : Node() {
            data_ = data;
            size_ = 1;
        }
    };

    Node* root_;

    int size(Node* h) {
        if (!h) { return 0; }
        return h->size_;
    }

    bool IsRed(Node* h) {
        if (!h) { return false; }
        return h->color_ == RED;
    }

    Node* RotateLeft(Node* h) {
        if (!h) { return nullptr; }
        Node* x = h->right_;
        h->right_ = x->left_;
        x->left_ = h;
        x->color_ = h->color_;
        h->color_ = RED;

        x->size_ = h->size_;
        h->size_ = size(h->left_) + size(h->right_) + 1;
        return x;
    }

    Node* RotateRight(Node* h) {
        if (!h) { return nullptr; }
        Node* x = h->left_;
        h->left_ = x->right_;
        x->right_ = h;
        x->color_ = h->color_;
        h->color_ = RED;
        x->size_ = h->size_;
        h->size_ = size(h->left_) + size(h->right_) + 1;
        return x;
    }

    /* Assuming h has its two children.*/
    void FlipColors(Node* h) {
        if (!h) { return; }
        h->left_->color_ = BLACK;
        h->right_->color_ = BLACK;
        h->color_ = RED;
    }

    Node* insert(Node* h, const T& data) {
        if (!h) {
            return new Node(data);
        }
        if (data < h->data_) {
            h->left_ = insert(h->left_, data);
        } else {
            h->right_ = insert(h->right_, data);
        }
        if (IsRed(h->right_) && !IsRed(h->left_)) {
            h = RotateLeft(h);
        }
        if (IsRed(h->left_) && IsRed(h->left_->left_)) {
            h = RotateRight(h);
        }
        if (IsRed(h->left_) && IsRed(h->right_)) {
            FlipColors(h);
        }
        h->size_ = size(h->left_) + size(h->right_) + 1;
        return h;
    }

    void print(Node* h) {
        if (!h) { return; }
        print(h->left_);
        std::cout << h->data_ << std::endl;
        print(h->right_);
    }

    int height(Node* h) {
        if (!h) { return 0; }
        int l = height(h->left_);
        int r = height(h->right_);
        if (h->left_ && h->left_->color_ == RED) {
            l--;
        }
        return std::max(l, r) + 1;
    }
};
#endif
