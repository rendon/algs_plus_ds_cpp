#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "word_break.h"

using namespace std;

TEST(WordBreak, FastMan) {
    vector<string> words = {"fast", "man"};
    string sentence = "fastman";
    WordBreak wb;
    EXPECT_EQ(1, wb.find(sentence, words));
}


TEST(WordBreak, TheNoteBookIsAllRight) {
    vector<string> words = {"the", "note", "book", "notebook",
                            "is", "all", "right", "allright"};
    string sentence = "thenotebookisallright";
    WordBreak wb;
    EXPECT_EQ(4, wb.find(sentence, words));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
