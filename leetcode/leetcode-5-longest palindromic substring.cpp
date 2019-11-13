#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

//    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//    示例 1：
//
//    输入: "babad"
//    输出: "bab"
//    注意: "aba" 也是一个有效答案。
//    示例 2：
//
//    输入: "cbbd"
//    输出: "bb"
//
//    Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//    Example 1:
//
//    Input: "babad"
//    Output: "bab"
//    Note: "aba" is also a valid answer.
//    Example 2:
//
//    Input: "cbbd"
//    Output: "bb"



class Solution {
public:
    // 方法1：暴力法，时间复杂度 O(n^3) 空间复杂度 O(1)
    string longestPalindrome(string s){
        int len = s.size();
        if(len < 2){
            return s;
        }
        int max_len = 1;
        string res(1, s[0]);
        for(int i = 0; i < len - 1; ++i){
            for(int j = i + 1; j < len; ++j){  // 遍历 s 的所有子串，判断每个子串是否回文，取最长
                int cur_len = j - i + 1;
                if(cur_len > max_len && isPalindrome(s, i, j)){
                    max_len = cur_len;
                    res = s.substr(i, cur_len);
                }
            }
        }
        return res;
    }
    // 判断字符串 s 的子串 s[left] ~ s[right] 是否是回文串
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }



    // 方法2：中心扩展法，时间复杂度 O(n^2) 空间复杂度 O(1)
    string longestPalindrome2(string s){
        int len = s.size();
        if(len < 2){
            return s;
        }
        int substr_start = 0, substr_end = 0;  // 回文子串的起始下标
        int max_len = 0;
        for(int i = 0; i < len; ++i){
            int len1 = expandAroundCenter(s, i, i);         // s 长度为奇数的情况，中心为一个字符
            int len2 = expandAroundCenter(s, i, i + 1);     // s 长度为偶数的情况，中心为两个字符
            int len = max(len1, len2);
            if(len > max_len){
                substr_start = i - (len - 1) / 2;
                substr_end = i + len / 2;
                max_len = substr_end - substr_start + 1;
            }
        }
        return s.substr(substr_start, max_len);
    }

    // 中心扩展判断字符串是否是回文
    int expandAroundCenter(string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        return right - left - 1;  // 不相等才结束，所以 - 1
    }


    // 方法3：动态规划法，时间复杂度 O(n^2) 空间复杂度 O(n^2)
    // 设 s[l, r] 表示子串 sl...sr， dp[l][r] 表示子串 s[l, r] 是否是回文串
    //
    string longestPalindrome3(string s){
        int len = s.size();
        if(len < 2){
            return s;
        }
        int max_len = 1;
        string res(1, s[0]);
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        for(int r = 1; r < len; ++r){
            for(int l = 0; l < r; ++l){  // 区间慢慢放大
                if(s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])){
                    dp[l][r] = true;
                    if(r - l + 1 > max_len){
                        max_len = r - l + 1;
                        res = s.substr(l, max_len);
                    }
                }
            }
        }
        return res;
    }

};

int main(){
    Solution s;
    return 0;
}
