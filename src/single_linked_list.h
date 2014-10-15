#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iterator>
using namespace std;

template<typename T>
class SingleLinkedList {

public:
    class Node {
        public:
            T data;
            Node *next;

            Node() { next = nullptr; } 

            Node(T data)
            {
                this->data = data;
                next = nullptr;
            }
    };

    class const_iterator;

    class iterator : std::iterator<std::input_iterator_tag, T> {
        private:
            Node *ptr;
            friend class const_iterator;
        public:
            iterator() {}
            iterator(Node *head)
            {
                ptr = head;
            }

            iterator& operator++()
            {
                ptr = ptr->next;
                return *this;
            }

            iterator operator++(int)
            {
                iterator temp = *this;
                ptr = ptr->next;
                return temp;
            }

            bool operator!=(const iterator& that)
            {
                return ptr != that.ptr;
            }

            T& operator*()
            {
                return ptr->data;
            }
    };

    class const_iterator : std::iterator<std::input_iterator_tag, T> {
        private:
            const Node *ptr;
        public:
            const_iterator() {}
            const_iterator(const Node *head)
            {
                ptr = head;
            }

            const_iterator(const iterator &other)
            {
                ptr = other.ptr;
            }

            const_iterator& operator++()
            {
                ptr = ptr->next;
                return *this;
            }

            const_iterator operator++(int)
            {
                const_iterator temp = *this;
                ptr = ptr->next;
                return temp;
            }

            bool operator!=(const const_iterator& that)
            {
                return ptr != that.ptr;
            }

            const T& operator*()
            {
                return ptr->data;
            }
    };

    SingleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool push_front(T data)
    {
        Node *node = new Node(data);
        if (!node) {
            return false;
        }

        if (head == nullptr) {
            head = node;
        } else {
            node->next = head;
            head = node;
        }

        return true;
    }

    bool push_back(T data)
    {
        Node *node = new Node(data);
        if (!node) {
            return false;
        }

        // The list is empty
        if (tail == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        return true;
    }

    bool pop_front()
    {
        if (head == nullptr) {
            return false;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        return true;
    }

    bool pop_back()
    {
        if (tail == nullptr) {
            return false;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node *node = head;
            while (node->next != tail) {
                node = node->next;
            }

            delete node->next;
            node->next = nullptr;
            tail = node;
        }

        return true;
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    // const_iterator begin() const
    // {
    //     return const_iterator(head);
    // }

    // const_iterator end() const
    // {
    //     return const_iterator(nullptr);
    // }

private:
    Node *head, *tail;
};
#endif

