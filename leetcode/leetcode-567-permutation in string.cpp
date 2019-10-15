#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
 *
 * Example 1:
 *
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * Example 2:
 *
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 */

class Solution {
public:
    // 方法1：双指针法，先用数组存下 s1 中字符出现的次数，再使用双指针遍历 s2，检查是否有满足要求的子串 220ms 19%
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 > len2 || len1 == 0 || len2 == 0){
            return false;
        }
        vector<int> char_count(26, 0);
        for(int i = 0; i < len1; i++){
            char_count[s1[i] - 'a']++;
        }
        int left = 0;
        int right = 0;
        int sub_len = 0;
        vector<int> temp(char_count);  // 用于减次数
        while(left <= len2 - len1){
            if(temp[s2[right] - 'a'] > 0 ){
                temp[s2[right] - 'a']--;
                sub_len++;
                right++;
            }else{
                left++;
                right = left;
                sub_len = 0;
                temp = char_count;
            }
            if(sub_len == len1){
                return true;
            }
        }
        return false;
    }
    // 4ms 99%
    bool checkInclusion2(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 > len2 || len1 == 0 || len2 == 0){
            return false;
        }
        vector<int> char_count(26, 0);
        for(int i = 0; i < len1; i++){
            char_count[s1[i] - 'a']++;
        }
        int left = 0;
        int right = 0;
        int sub_len = 0;
        for (; right < len2; right++) {
            if (--char_count[s2[right] - 'a'] >= 0){
                sub_len++;
            }
            while (right - left + 1 > sub_len){
                if (++char_count[s2[left++] - 'a'] > 0){
                    sub_len--;
                }
            }
            if (sub_len == len1) return true;
        }

        return false;
    }

    // 方法2：先求 s1 的字符统计数组，再遍历 s2，求 s2 中与 s1 相同长度的子串的字符统计数组，比较两个数组里的出现次数是否相等。
    // 220ms 19%
    bool checkInclusion3(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 > len2 || len1 == 0 || len2 == 0){
            return false;
        }
        vector<int> char_count(26, 0);
        for(int i = 0; i < len1; i++){
            char_count[s1[i] - 'a']++;
        }

        for(int i = 0; i <= len2 - len1; i++){
            string sub_s2 = s2.substr(i, len1);
            vector<int> char_count2(26, 0);
            for(int j = 0; j < sub_s2.size(); j++){
                char_count2[sub_s2[j] - 'a']++;
            }
            int k = 0;
            for(; k < len1; k++){
                if(char_count[s1[k] - 'a'] != char_count2[s1[k] - 'a']){
                    break;
                }
            }
            if(k == len1){
                return true;
            }
        }
        return false;
    }

};


int main(){
    return 0;
}
