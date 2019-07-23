#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

/* Given a string, find the length of the longest substring without repeating characters.
 *
 * Example 1:
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * Example 2:
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 *              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */


class Solution {
public:
    // 方法1，暴力法，略

    // 方法2，滑动窗口1
    // 使用一个set存储当前子串，判断当前的s[j]是否存在set中，若存在，表示有重复元素，当前以s[i]开头的子串已达到最大长度，
    // 此时将set中的set[i]删除，i++，即右移一位
    int lengthOfLongestSubstring2(string s) {
        set<char> substr_set;
        int s_len = s.length();
        int i = 0, res = 0, j = 0;
        while(i < s_len && j < s_len) {
            if(substr_set.find(s[j]) == substr_set.end()) {     // 如果set中没有包含s[j]，将其插入set中
                substr_set.insert(s[j++]);
                res = max(res, j - i);
            } else {                                            //  如果s[j]已存在set中，删除s[i]，i++
                substr_set.erase(s[i++]);
            }
        }

        return res;
    }

    // 方法3，滑动窗口2
    // 使用一个map存储当前子串，以及子串中每一个字符在s中的索引（下标）的下一位
    // 当s[j]存在于map中时，当前以s[i]开头的子串已达最大长度，
    // i 直接跳到map中与s[j]一样的字符的下标的下一位
    int lengthOfLongestSubstring3(string s) {
        map<char, int> substr_map;                                  // 记录子串字符以及字符的索引（下标）的下一位
        int s_len = s.length();
        int i = 0, res = 0, j = 0;
        for( ; j < s_len; j++) {
            map<char, int>::iterator iter = substr_map.find(s[j]);  // 查找字符 s[j] 是否已在子串中，即map中
            if( iter != substr_map.end()) {                         // 若在，表示字符重复
                i = max(iter->second, i);                           // 重复字符下一个位置和当前i比较，防止 i 往回跳
                substr_map[s[j]] = j + 1;   	                    // 更新重复字符s[j]的位置索引，取靠后的位置。 这两行实现了不需要删除map中跳过的字符
            }else{
                substr_map.insert( pair<char, int>(s[j], j + 1 ) ); // 若不重复，插入s[j]及其索引的下一位
            }
            res = max(res, j - i + 1);                              // 更新最长无重复子串的长度
        }
        return res;
    }

    // 方法4，字符集
    // 思路和优化版滑动窗口类似  ，使用数组 index 存储所有字符在 s 中的索引的下一位置
    // 刚开始 index[s[j]] 都为0， i 也一直为0， 当出现重复元素时， i 直接跳到重复元素当前存在index数组中的下标位置。
    int lengthOfLongestSubstring4(string s) {
        int s_len = s.length();
        int index[128] = {0};
        int i = 0, res = 0, j = 0;
        for( ; j < s_len; j++) {            // 遍历 s 字符串
            i   = max(index[s[j]], i);      // 更新 i ，当没遇到重复元素时，i 一直保持不变。
            res = max(res, j - i + 1);
            index[s[j]] = j + 1;
        }
        return res;
    }

};
int main() {
    Solution a;
    string s = "tmmzuxt";//"abcdaefghaij";
    cout << a.lengthOfLongestSubstring3(s) << " " << a.lengthOfLongestSubstring2(s);
    return 0;
}
