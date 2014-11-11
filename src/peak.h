#ifndef PEAK_H_
#define PEAK_H_

#include <vector>
#include <algorithm>
//#include <utility>
using namespace std;
class Peak {
public:
    Peak() { }
    int find1d(vector<int> &A) {
        int n = A.size();
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (mid > 0 && A[mid-1] >= A[mid]) {
                high = mid;
            } else if (mid + 1 < n && A[mid] <= A[mid+1]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        return -1; // Is that possible?
    }

    pair<int, int> find2d(vector<vector<int> > &A) {
        int n = A.size();
        int low = 0, high = n;
        pair<int, int> ans;
        while (low < high) {
            int mid = (low + high) / 2;
            int i = max_element(begin(A[mid]), end(A[mid])) - begin(A[mid]);
            if (high - low == 1) {
                ans.first = mid;
                ans.second = i;
                break;
            } else {
                if (mid > 0 && A[mid-1][i] >= A[mid][i]) {
                    high = mid;
                } else if (mid + 1 < n && A[mid][i] <= A[mid+1][i]) {
                    low = mid + 1;
                } else {
                    ans.first = mid;
                    ans.second = i;
                    break;
                }
            }
        }

        return ans;
    }
};

#endif
