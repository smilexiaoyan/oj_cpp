//
// Created by zhang on 2022/6/14.
//
#include <iostream>
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (!count_same(s1, s2, 0, s1.length(), 0, s2.length())) {
            return false;
        }

        return f(s1, s2, 0, s1.length());
    }

    bool f(string s, string d, int start, int end) {
        if (end == start) {
            return true;
        }
        if (end - start == 1) {
            return s.at(start) == d.at(start);
        }
        for (int i = start + 1; i < end; ++i) {
            if (count_same(s, d, start, i, start, i)) {
                if (f(s, d, start, i) && f(s, d, i, end)) {
                    return true;
                }
            }
            if (count_same(s, d, start, i, end - (i - start), end)) {
                auto s2 = s;
                swap(s2, start, end, i);
                if (f(s2, d, start, start + (end - i)) && f(s2, d, start + (end - i), end)) {
                    return true;
                }
            }
        }
        return false;

    }

    static void swap(string &s, int start, int end, int div) {
        auto temp = s.substr(div, end - div) + s.substr(start, div - start);
        s.replace(start, end - start, temp);
    }

    static bool count_same(string &s, string &d, int start, int end, int start2, int end2) {
        unordered_map<char, int> m{};
        for (int i = start; i < end; ++i) {
            auto it = m.find(s[i]);
            if (it == m.end()) {
                m.insert({s[i], 1});
            } else {
                ++(it->second);
            }

        }
        for (int i = start2; i < end2; ++i) {
            auto it = m.find(d[i]);
            if (it == m.end()) {
                m.insert({d[i], -1});
            } else {
                --(it->second);
            }
        }
        for (auto &item: m) {
            if (item.second != 0) {
                return false;
            }
        }
        return true;
    }

};