//
// Created by zhang on 2022/6/14.
//
#include <iostream>
#include "string"
#include "vector"

using namespace std;

class Solution {
public:

    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        string blanks;
        blanks.resize(maxWidth, ' ');

        unsigned int remain = maxWidth + 1;
        vector<string> result{};
        vector<string> lines{};
        for (auto &word: words) {
            if (word.length() >= remain) {
                unsigned int fix_len = lines.size() - 1;
                if (fix_len == 0) {
                    result.push_back(lines[0] + blanks.substr(0, remain));
                } else {
                    unsigned int quotient = remain / fix_len;
                    unsigned int remainder = remain % fix_len;
                    string line{lines[0]};
                    for (auto i = 1; i < lines.size(); i++) {
                        line.append(blanks.substr(0, quotient + 1 + (i > remainder ? 0 : 1)));
                        line.append(lines[i]);
                    }
                    result.push_back(line);
                }

                lines.clear();
                remain = maxWidth + 1;
            }
            lines.push_back(word);
            remain -= word.length() + 1;
        }
        if (!lines.empty()) {
            string line{lines[0]};
            for (auto i = 1; i < lines.size(); i++) {
                line.append(' ' + lines[i]);
            }
            line.append(blanks.substr(0, remain));
            result.push_back(line);
        }
        return result;
    }
};