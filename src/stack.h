#ifndef STACK_H_
#define stack_H_
#include <cassert>
template<typename T>
class Stack {
private:
    size_t size_;
    class Node {
    public:
        T item;
        Node *next;
        Node() {}
        Node(const T &t, Node *next) {
            item = t;
            this->next = next;
        }
    };

    Node *top_;
public:
    Stack() {
        size_ = 0;
        top_ = nullptr;
    }

    bool empty() {
        return size_ == 0;
    }

    void push(const T &t) {
        Node *n = top_;
        top_ = new Node(t, n);
        if (!top_) { }

        size_++;
    }

    T& top() {
        assert(!empty());
        return top_->item;
    }

    void pop() {
        assert(!empty());
        Node *t = top_;
        top_ = top_->next;
        delete t;
        size_--;
    }
};
#endif
