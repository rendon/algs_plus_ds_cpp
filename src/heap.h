#ifndef HEAP_H_
#define HEAP_H_
#include <string>
#include <algorithm>
using namespace std;
const int MIN_CAPACITY = 1024;

template <typename T>
class Heap {
private:
    int size_;
    T *H;

    int left(int k) const {
        return 2 * k;
    }

    int right(int k) const {
        return 2 * k + 1;
    }

    int parent(int k) const {
        return (k - 1) / 2;
    }

    void heapify(int k) {
        while (k < size_ / 2) {
            int l = left(k);
            int r = right(k);
            if (r < size_) {
                if (H[k] < H[l] || H[k] < H[r]) {
                    if (H[l] < H[r]) {
                        swap(H[k], H[r]);
                        k = r;
                    } else {
                        swap(H[k], H[l]);
                        k = l;
                    }
                } else {
                    break;
                }
            } else if (H[k] < H[l]) {
                swap(H[k], H[l]);
                k = l;
            } else {
                break;
            }
        }
    }

public:
    Heap() {
        size_ = 0;
        H = new T[MIN_CAPACITY];
    }

    void insert(const T &val) {
        H[size_++] = val;
        int k = size_ - 1;
        int p = parent(k);
        while (p >= 0 && H[p] < H[k]) {
            swap(H[p], H[k]);
            k = p;
            p = parent(k);
        }
    }

    void print() const {
        cout << "Elements:" << endl;
        for (int i = 0; i < size_; i++) {
            cout << H[i] << " ";
        } 
        cout << endl;
    }

    const T& top() const {
        return H[0];
    }

    void remove() {
        H[0] = H[size_-1];
        size_--;
        heapify(0);
    }

    int size() const {
        return size_;
    }

    bool empty() const {
        return size_ <= 0;
    }

    void sort(T A[]) {
        int pos = size_ - 1;
        while (size_ > 0) {
            A[pos--] = H[0];
            size_--;
            swap(H[0], H[size_]);
            heapify(0);
        }
    }

    ~Heap() {
        //delete H;
    }
};
#endif
