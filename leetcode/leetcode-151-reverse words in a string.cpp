#include<iostream>
#include<string>
using namespace std;

//    给定一个字符串，逐个翻转字符串中的每个单词。
//    示例 1：
//    输入: "the sky is blue"
//    输出: "blue is sky the"
//
//    示例 2：
//    输入: "  hello world!  "
//    输出: "world! hello"
//    解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//
//    示例 3：
//    输入: "a good   example"
//    输出: "example good a"
//    解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//
//    说明：
//    无空格字符构成一个单词。
//    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//
//    进阶：
//    请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
//
//    Given an input string, reverse the string word by word.
//
//    Example 1:
//    Input: "the sky is blue"
//    Output: "blue is sky the"
//    Example 2:
//    Input: "  hello world!  "
//    Output: "world! hello"
//    Explanation: Your reversed string should not contain leading or trailing spaces.
//    Example 3:
//    Input: "a good   example"
//    Output: "example good a"
//    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//    Note:
//    A word is defined as a sequence of non-space characters.
//    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
//    You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//    Follow up:
//    For C programmers, try to solve it in-place in O(1) extra space.


class Solution {
public:
    // 方法1： 先整个翻转 s 再翻转每个单词，时间复杂度有点高
    string reverseWords(string s) {
        string res = "";
        reverse(s.begin(), s.end()); // 先整个翻转 s
        int p = 0;                   //  用于遍历字符串 s
        bool preIsBlank = false;     //  用于标记上一个字符是否是空格
        string temp;                 //  用于暂存单词
        while(p < s.size() ){        // 再逐个翻转每个单词并存入 res 中

            if(s[p] == ' ' && preIsBlank){  // 连续空白
                preIsBlank = true;
            }else if( (s[p] == ' ' && !preIsBlank) || p == s.size() - 1 ){ // 遇到空格，且之前字符是单词；或者遍历到字符串尾部
                if(p == s.size() - 1 && s[p] != ' '){
                    temp.push_back(s[p]);
                }
                reverse(temp.begin(), temp.end());
                if(!res.empty()){       // 跳过开头是空格的情况
                    res = res + ' ' + temp;
                }else{
                    res += temp;
                }
                temp.clear();
                preIsBlank = true;
            }else if(s[p] != ' '){      // 将单词存入 temp 中
                temp.push_back(s[p]);
                preIsBlank = false;
            }
            ++p;
        }
        return res;
    }

    // 方法2：从头遍历 s ，并用 temp 存储每个单词，当单词结束时将 temp 插入结果字符串 res 的头部
    string reverseWords(string s) {
        string res = "";
        int len = s.size();
        int p = 0;
        while(p < len){
            while(s[p] == ' ' && p < len)
                p++;
            if(p == len) break;
            string temp = "";
            while(s[p] != ' ' && p < len){  // 将单词存入 temp 中
                temp += s[p];
                p++;
            }
            res = temp + ' ' + res;         // 插入 res 头部
        }
        res.pop_back();                     // 删除插入第一个单词时多插入的空格
        return res;
    }



    // 自己实现的 reverse，暂时没用到
    void reverse(string &s, int begin, int end){
        while(begin < end && end < s.size()){
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            ++begin;
            --end;
        }
    }
};
int main(){
    return 0;
}
