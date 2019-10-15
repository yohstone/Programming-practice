#include<iostream>
using namespace std;

/* Given two strings s and t , write a function to determine if t is an anagram of s.
 *
 * Example 1:
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 *
 * Input: s = "rat", t = "car"
 * Output: false
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */




class Solution {
public:

    // 用数组或哈希表，统计字符出现的次数
    bool isAnagram_0(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        if(len_s != len_t){
            return false;
        }else{
            int words[26] = {0};
            for(int i = 0; i < len_s; i++){
                words[s[i] - 'a']++;
                words[t[i] - 'a']--;
            }
            for(int i = 0; i < 26; i++){
                if(words[i] < 0){
                    return false;
                }
            }
            return true;
        }
    }


    // 失败的思路，有空继续思考能否解决
    bool isAnagram_0(string s, string t) {
        int res = 0;
        int len_s = s.length();
        int len_t = t.length();
        int s_sum = 0;
        int t_sum = 0;
        if(len_s != len_t){
            return false;
        }else{
            for(int i = 0; i < len_s; i++){
                res = res ^ s[i];
                res = res ^ t[i];
                s_sum += s[i];              // 相加的是字符对应的ascii码值
                t_sum += t[i];              // 相加的是字符对应的ascii码值
            }
        }
        return res == 0 && s_sum == t_sum;  // 异或为0，且字符和相等，则字符串相同
    }
};

int main(){
    return 0;
}
