#ifndef TRIE_H_
#define TRIE_H_
#include <string>
#include <map>
#include <vector>
using std::string;
using std::map;
using std::vector;

class Node {
    private:
        char key_;
        bool isEnd_;
        map<char, Node*> children_;
    public:
        Node() {
            key_ = 0;
            isEnd_ = false;
        }

        Node(char key) {
            this->key_ = key;
            this->isEnd_ = false;
        }

        char getKey() {
            return key_;
        }

        Node *get(char k) {
            if (children_.count(k) == 0) {
                return nullptr;
            } else {
                return children_[k];
            }
        }

        void put(char k, Node *node) {
            children_[k] = node;
        }

        bool isEnd() {
            return isEnd_;
        }

        void setIsEnd(bool value) {
            this->isEnd_ = value;
        }

        ~Node() {
            for (auto &item : children_) {
                delete item.second;
            }
        }
};

class Trie {
    private:
        Node *root_;
        Node *current_;

        void insert(Node *node, string &str, int pos) {
            if (pos == int(str.length())) {
                return;
            }

            char k = str[pos];
            Node *next = node->get(k);
            if (next ==  nullptr) {
                next = new Node(k);
                if (pos + 1 == int(str.length())) {
                    next->setIsEnd(true);
                }
                node->put(k, next);
            }

            insert(next, str, pos + 1);
        }

    public:
        Trie() {
            root_ = new Node('\0');
            current_ = root_;
        }

        Trie(vector<string> dict) {
            root_ = new Node();
            current_ = root_;
            for (string word : dict) {
                insert(root_, word, 0);
            }
        }

        bool move(char k) {
            if (current_->get(k) == nullptr) {
                return false;
            }

            current_ = current_->get(k);
            return true;
        }


        void reset() {
            current_ = root_;
        }

        Node *getCurrent() {
            return current_;
        }

        void setCurrent(Node *current) {
            this->current_ = current;
        }
        bool isEndOfWord() {
            return current_->isEnd();
        }

        ~Trie() {
            delete root_;
        }
};
#endif
