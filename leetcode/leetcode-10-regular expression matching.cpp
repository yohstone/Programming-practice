#include<iostream>
#include<string>
using namespace std;

//    Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//
//    '.' Matches any single character.
//    '*' Matches zero or more of the preceding element.
//    The matching should cover the entire input string (not partial).
//
//    Note:
//
//    s could be empty and contains only lowercase letters a-z.
//    p could be empty and contains only lowercase letters a-z, and characters like . or *.
//    Example 1:
//
//    Input:
//    s = "aa"
//    p = "a"
//    Output: false
//    Explanation: "a" does not match the entire string "aa".
//    Example 2:
//
//    Input:
//    s = "aa"
//    p = "a*"
//    Output: true
//    Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//    Example 3:
//
//    Input:
//    s = "ab"
//    p = ".*"
//    Output: true
//    Explanation: ".*" means "zero or more (*) of any character (.)".
//    Example 4:
//
//    Input:
//    s = "aab"
//    p = "c*a*b"
//    Output: true
//    Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
//    Example 5:
//
//    Input:
//    s = "mississippi"
//    p = "mis*is*p*."
//    Output: false

//    给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
//    '.' 匹配任意单个字符
//    '*' 匹配零个或多个前面的那一个元素
//    所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//
//    说明:
//
//    s 可能为空，且只包含从 a-z 的小写字母。
//    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。


class Solution {
public:
    // 方法1：递归法
    //    如果模式串中有星号，它会出现在第二个位置，即 p[1] 。
    //    这种情况下，我们可以直接忽略模式串中这一部分，或者删除匹配串的第一个字符，前提是它能够匹配模式串当前位置字符，即
    //    p[0]。如果两种操作中有任何一种使得剩下的字符串能匹配，那么匹配串和模式串就可以被匹配。
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.'); // 判断当前两个串的第一个字符是否匹配
        if(p.size() > 1 && p[1] == '*'){                // 有 * 的时候
            return isMatch(s, p.substr(2))              // 跳过 *
            || (firstMatch && isMatch(s.substr(1), p)); // 不跳过 *
        }else{                                          // 无 * 的时候
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};
int main(){
    return 0;
}
