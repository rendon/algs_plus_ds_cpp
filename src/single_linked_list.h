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

    Node *head;

    class SingleLinkedListIterator : iterator<input_iterator_tag, T> {
        private:
            Node *ptr;
        public:
            SingleLinkedListIterator(Node *head)
            {
                ptr = head;
            }

            SingleLinkedListIterator operator++()
            {
                SingleLinkedListIterator temp = *this;
                ptr = ptr->next;
                return temp;
            }

            bool operator!=(const SingleLinkedListIterator& that)
            {
                return ptr != that.ptr;
            }

            T& operator*()
            {
                return ptr->data;
            }
    };

    SingleLinkedList()
    {
        head = nullptr;
    }

    bool add(T data)
    {
        Node *node = new Node(data);
        if (!node) {
            return false;
        }

        if (head == nullptr) {
            head = node;
            return true;
        }

        node->next = head;
        head = node;

        return true;
    }

    SingleLinkedListIterator begin()
    {
        return SingleLinkedListIterator(head);
    }

    SingleLinkedListIterator end()
    {
        return SingleLinkedListIterator(NULL);
    }
};
#endif

