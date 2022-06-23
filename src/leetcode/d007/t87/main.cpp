//
// Created by zhang on 2022/6/14.
//
#include <iostream>
#include "Solution.cpp"

int main() {
    Solution solution{};
//    std::cout << solution.isScramble("aa", "aa") << std::endl;
//    std::cout << solution.isScramble("a", "a") << std::endl;
//    std::cout << solution.isScramble("abc", "cba") << std::endl;
//    std::cout << solution.isScramble("abcdbdacbdac", "bdacabcdbdac") << std::endl;
//    std::cout << solution.isScramble("ccbbcaccbccbbbcca", "ccbbcbbaabcccbccc") << std::endl;
//    std::cout << solution.isScramble("great", "rgeat") << std::endl;
//    std::cout << solution.isScramble("abcde", "caebd") << std::endl;
    std::cout << solution.isScramble("eebaacbcbcadaaedceaaacadccd",
                                     "eadcaacabaddaceacbceaabeccd") << std::endl;
    return 0;
}