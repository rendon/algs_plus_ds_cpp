#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "trie.h"
using namespace std;

vector<string> solutions;

void find(Trie &trie, const string &sentence, string &spaces, int pos) {
    if (pos == int(sentence.length())) {
        string sol;
        for (int i = 0; i < int(sentence.length()); i++) {
            sol += sentence[i];
            if (spaces[i] == ' ') {
                sol += ' ';
            }
        }
        solutions.push_back(sol);
    } else {
        char k = sentence[pos];
        Node *current = trie.getCurrent();
        if (trie.isEndOfWord()) {
            trie.reset();
            spaces[pos-1] = ' ';
            trie.move(k);
            find(trie, sentence, spaces, pos + 1);
            spaces[pos-1] = '-';
            trie.setCurrent(current);
        }


        if (trie.move(k)) {
            find(trie, sentence, spaces, pos + 1);
            trie.setCurrent(current);
        }
    }
}

void find(vector<string> dict, string sentence) {
    solutions.clear();
    Trie trie(dict);
    string spaces(sentence.length(), '-');
    find(trie, sentence, spaces, 0);
}

TEST(Trie, FastMan) {
    vector<string> dict = {"fast", "man"};
    string sentence = "fastman";
    find(dict, sentence);
    ASSERT_EQ(1u, solutions.size());
    ASSERT_EQ("fast man", solutions[0]);
}

TEST(Trie, TheNoteBookIsAllRight) {
    vector<string> dict = {"the", "note", "book", "notebook",
                            "is", "all", "right", "allright"};
    string sentence = "thenotebookisallright";
    find(dict, sentence);
    ASSERT_EQ(4u, solutions.size());
    EXPECT_EQ("the note book is all right", solutions[0]);
    EXPECT_EQ("the note book is allright", solutions[1]);
    EXPECT_EQ("the notebook is all right", solutions[2]);
    EXPECT_EQ("the notebook is allright", solutions[3]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
