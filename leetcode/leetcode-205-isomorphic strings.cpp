#include<iostream>
#include<vector>
using namespace std;

//    给定两个字符串 s 和 t，判断它们是否是同构的。
//
//    如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
//
//    所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
//
//    示例 1:
//
//    输入: s = "egg", t = "add"
//    输出: true
//    示例 2:
//
//    输入: s = "foo", t = "bar"
//    输出: false
//    示例 3:
//
//    输入: s = "paper", t = "title"
//    输出: true
//    说明:
//    你可以假设 s 和 t 具有相同的长度。
//
//    Given two strings s and t, determine if they are isomorphic.
//
//    Two strings are isomorphic if the characters in s can be replaced to get t.
//
//    All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
//    Example 1:
//
//    Input: s = "egg", t = "add"
//    Output: true
//    Example 2:
//
//    Input: s = "foo", t = "bar"
//    Output: false
//    Example 3:
//
//    Input: s = "paper", t = "title"
//    Output: true
//    Note:
//    You may assume both s and t have the same length.



class Solution {
public:
    // 方法1：两个字符串相对位置的字符在本字符串第一次出现的位置相同，则为同构
    bool isIsomorphic(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if(len1 != len2) return false;

        for(int i = 0; i < len1; ++i){
            if(s.find(s[i]) != t.find(t[i])){
                return false;
            }
        }
        return true;
    }

    // 方法2：使用容器将俩字符串中各互相映射的字符下标存下，然后对比字符第一次出现的位置
    bool isIsomorphic2(string s, string, t){
        int len1 = s.size();
        int len2 = t.size();
        if(len1 != len2) return false;

        vector<int> v1(128, -1), v2(128, -1);
        for(int i = 0;i < s.size(); ++i){
            if(v1[s[i]] != v2[t[i]] ) return false;
            v1[s[i]] = v2[t[i]] = i;
        }
        return true;
    }
};


int main(){
    Solution s;

    return 0;
}
