#ifndef WORD_BREAK_H_
#define WORD_BREAK_H_
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;
using std::unordered_map;

const int MAX_LENGTH = 100;

class WordBreak {
private:
    unordered_map<string, bool> dict;
    string sentence;
    int dp[MAX_LENGTH][MAX_LENGTH];
public:
    WordBreak() {}
    int find(int l, int r) {
        if (r == int(sentence.length())) {
            return (l == r) ? 1 : 0;
        } else {
            if (dp[l][r] != -1) {
                return dp[l][r];
            }

            int sum = 0;
            int length = r - l + 1;
            string word = sentence.substr(l, length);
            if (dict.count(word) == 1) {
                sum += find(r + 1, r + 1);
            }

            sum += find(l, r + 1);
            dp[l][r] = sum;
            return sum;
        }
    }

    int find(string sentence, vector<string> words) {
        dict.clear();
        this->sentence = sentence;
        for (string w : words) {
            dict[w] = true;
        }

        int n = sentence.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        return find(0, 0);
    }
};
#endif
