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
    std::unordered_map<char, int> map{};

    bool isScramble(string s1, string s2) {
        for (int i = 0; i < s1.length(); i++) {
            map.emplace(s1[i], i);
        }
        return f(s2, 0, s2.length());
    }

    bool f(string &s, int start, int end) {
        if (end == start) {
            return true;
        }
        if (end - start == 1) {
            if(map.find(s.at(start)) == map.end()){
                return false;
            }
            return map.at(s.at(start)) == start;
        }
        for (int i = start + 1; i < end; ++i) {
            if (ff(s, start, i, start, i)) {
                if (f(s, start, i) && f(s, i, end)) {
                    return true;
                }
            }
            if (ff(s, start, i, end - (i - start), end)) {
                swap(start, end, i);
                if (f(s, start, i) && f(s, i, end)) {
                    return true;
                }
                swap(start, end, end - i);
            }
        }
        return false;

    }

    void swap(int start, int end, int div) {
        for (auto &item: map) {
            if (item.second >= start && item.second < end) {
                if (item.second < div) {
                    item.second += end - div;
                } else {
                    item.second -= div - start;
                }
            }
        }
    }

    bool ff(string &s, int start, int end, int range_start, int range_end) {
        for (int i = start; i < end; ++i) {
            auto val = map.at(s[i]);
            if (val < range_start || val >= range_end) {
                return false;
            }
        }
        return true;
    }

};