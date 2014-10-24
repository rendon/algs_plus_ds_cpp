#ifndef QUEUE_H_
#define QUEUE_H_
template<typename T>
class Queue {
private:
    size_t size_;
    class Node {
    public:
        T item;
        Node *prev;
        Node *next;
        Node() {
            prev = nullptr;
            next = nullptr;
        }

        Node(Node *prev, T element, Node *next) {
            this->item = element;
            this->prev = prev;
            this->next = next;
        }
    };

    Node *first, *last;

public:
    Queue() {
        first = nullptr;
        last = nullptr;
        size_ = 0;
    }

    void push(T element) {
        Node *l = last;
        last = new Node(l, element, nullptr);
        if (l == nullptr) {
            first = last;
        } else {
            l->next = last;
        }
        ++size_;
    }

    T front() const {
        //if (first == nullptr) { 
        //    return nullptr;
        //}

        return first->item;
    }

    void pop() {
        if (first != nullptr) {
            Node *next = first->next;
            delete first;
            first = next;
            if (next == nullptr) {
                last = nullptr;
            } else {
                next->prev = nullptr;
            }
            --size_;
        }
    }

    T back() const {
        if (last == nullptr) {
            return nullptr;
        }

        return last->item;
    }

    size_t size() {
        return size_;
    }

    ~Queue() {
        Node *next;
        while (first != nullptr) {
            next = first->next;
            delete first;
            first = next;
        }
    }
};
#endif
