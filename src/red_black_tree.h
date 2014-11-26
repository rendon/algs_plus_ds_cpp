/**
 * This implementation is based on Robert Sedgewick Red-Black Tree
 * implementation:
 *      http://algs4.cs.princeton.edu/33balanced/RedBlackBST.java.html.
 * This implementation is for didactic purposes and may have several bugs,
 * especially with deletion operations which I still don't understand so well.
 */
#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cassert>
const bool RED = true;
const bool BLACK = false;
template <typename T>
class RedBlackTree {
private:
    //region 
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

        Node* left() { return left_; }
        Node* right() { return right_; }
        bool color() { return color_; }
        T& data() { return data_; }
    };
    //endregion
    Node* root_;

    class iterator : std::iterator<std::input_iterator_tag, T> {
    private:
        Node* ptr_;
    public:
        iterator() : ptr_(nullptr) { }
        iterator(Node* ptr) : ptr_(ptr) { }
        T& operator*() {
            return ptr_->data_;
        }
        bool operator==(const iterator& that) const {
            return ptr_ == that.ptr_;
        }
        bool operator!=(const iterator& that) const {
            return ptr_ != that.ptr_;
        }
    };

    Node* min(Node* h) {
        if (!h) { return nullptr; }
        if (h->left_) {
            return min(h->left_);
        } else {
            return h;
        }
    }

    Node* max(Node* h) {
        if (!h) { return h; }
        if (h->right_) {
            return max(h->right_);
        } else {
            return h;
        }
    }

    int size(Node* h) {
        if (!h) { return 0; }
        return h->size_;
    }

    bool isRed(Node* h) {
        if (!h) { return false; }
        return h->color_ == RED;
    }

    Node* rotateLeft(Node* h) {
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

    Node* rotateRight(Node* h) {
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
    void flipColors(Node* h) {
        if (!h) { return; }
        assert(h->left() != nullptr);
        assert(h->right() != nullptr);
        h->left_->color_ = !h->left()->color();
        h->right_->color_ = !h->right()->color();
        h->color_ = !h->color_;
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
        if (isRed(h->right_) && !isRed(h->left_)) {
            h = rotateLeft(h);
        }
        if (isRed(h->left_) && isRed(h->left_->left_)) {
            h = rotateRight(h);
        }
        if (isRed(h->left_) && isRed(h->right_)) {
            flipColors(h);
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

    Node* moveRedLeft(Node* h) {
        flipColors(h);
        if (isRed(h->right()->left())) {
            h->right_ = rotateRight(h->right());
            h = rotateLeft(h);
        }
        return h;
    }

    Node* balance(Node* h) {
        //assert(h);
        if (isRed(h->right())) {
            h = rotateLeft(h);
        }
        if (isRed(h->left()) && isRed(h->left()->left())) {
            h = rotateRight(h);
        }
        if (isRed(h->left()) && isRed(h->right())) {
            flipColors(h);
        }
        h->size_ = size(h->left()) + size(h->right()) + 1;
        return h;
    }
    
    Node* deleteMin(Node* h) {
        if (!h || !h->left_) {
            return nullptr;
        }
        if (!isRed(h->left_) && !isRed(h->left_->left_)) {
            h = moveRedLeft(h);
        }

        h->left_ = deleteMin(h->left_);
        return balance(h);
    }

    Node* moveRedRight(Node* h) {
        //assert(h);
        flipColors(h);
        if (isRed(h->left()->left())) {
            h = rotateRight(h);
        }
        return h;
    }

    Node* deleteMax(Node* h) {
        if (isRed(h->left())) {
            h = rotateRight(h);
        }
        if (!h->right()) {
            return nullptr;
        }
        if (!isRed(h->right_) && !isRed(h->right()->left())) {
            h = moveRedRight(h);
        }
        h->right_ = deleteMax(h->right());

        return balance(h);
    }

    Node* find(Node* h, const T& data) {
        if (!h) { return nullptr; }
        if (data < h->data()) {
            return find(h->left(), data);
        } else if (h->data() < data) {
            return find(h->right(), data);
        } else {
            return h;
        }
    }

    Node* erase(Node* h, const T& data) {
        if (!h) { return nullptr; }
        if (data < h->data()) {
            if (!isRed(h->left()) && h->left() && !isRed(h->left()->left())) {
                h = moveRedLeft(h);
            }
            h->left_ = erase(h->left(), data);
        } else {
            if (isRed(h->left())) {
                h = rotateRight(h);
            }
            if (!isRed(h->right()) && h->right() && !isRed(h->right()->left())) {
                h = moveRedRight(h);
            }
            if (data == h->data() && !h->right()) {
                return nullptr;
            }
            if (data == h->data()) {
                Node* x = min(h->right());
                h->data_ = x->data();
                h->right_ = deleteMin(h->right());
            } else {
                h->right_ = erase(h->right(), data);
            }
        }
        return balance(h);
    }

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

    iterator min() {
        return iterator(min(root_));
    }

    iterator max() {
        return iterator(max(root_));
    }

    bool empty() {
        return size(root_) == 0;
    }

    void deleteMin() {
        if (!isRed(root_->left()) && !isRed(root_->right())) {
            root_->color_ = RED;
        }
        root_ = deleteMin(root_);
        if (!empty()) {
            root_->color_ = BLACK;
        }
    }

    void deleteMax() {
        if (empty()) { return; }
        if (!isRed(root_->left()) && !isRed(root_->right())) {
            root_->color_ = RED;
        }
        root_ = deleteMax(root_);
        if (!empty()) {
            root_->color_ = BLACK;
        }
    }

    void erase(const T& data) {
        if (!find(root_, data)) { return; }
        if (!isRed(root_->left()) && !isRed(root_->right())) {
            root_->color_ = RED;
        }
        root_ = erase(root_, data);
        if (!empty()) {
            root_->color_ = BLACK;
        }
    }

    iterator find(const T& data) {
        return iterator(find(root_, data));
    }

    iterator end() {
        return iterator(nullptr);
    }
};
#endif
