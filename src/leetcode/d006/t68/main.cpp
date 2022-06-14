//
// Created by zhang on 2022/6/14.
//
#include <iostream>
#include "Solution2.cpp"

int main() {
    Solution solution{};
//    vector <string> words{"This", "is", "an", "example", "of", "text", "justification."};
//    vector <string> words{"What","must","be","acknowledgment","shall","be"};
    vector<string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a",
                         "computer.", "Art", "is", "everything", "else", "we", "do"};
    auto result = solution.fullJustify(words, 20);

    for (auto &item: result) {
        std::cout << item << std::endl;
    }
    return 0;
}