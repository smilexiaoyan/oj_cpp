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
        unsigned int remain = maxWidth + 1;
        vector<string> result{};
        unsigned int start = 0;
        unsigned int end = 0;
        for (; end < words.size(); end++) {
            auto &word = words[end];
            if (word.length() >= remain) {
                unsigned int fix_len = end - start - 1;
                if (fix_len == 0) {
                    result.push_back(words[start].append(remain, ' '));
                } else {
                    unsigned int quotient = remain / fix_len;
                    unsigned int remainder = remain % fix_len;
                    string line{words[start]};
                    line.reserve(maxWidth);
                    for (auto i = start + 1; i < end; i++) {
                        line.append(quotient + 1 + (i - start > remainder ? 0 : 1), ' ');
                        line.append(words[i]);
                    }
                    result.push_back(line);
                }

                start = end;
                remain = maxWidth + 1;
            }
            remain -= word.length() + 1;
        }
        if (end - start > 0) {
            string line{words[start]};
            line.reserve(maxWidth);
            for (auto i = start + 1; i < end; i++) {
                line.append(' ' + words[i]);
            }
            line.append(remain, ' ');
            result.push_back(line);
        }
        return result;
    }
};