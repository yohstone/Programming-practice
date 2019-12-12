#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//    给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//    示例 1:
//
//    输入: "Let's take LeetCode contest"
//    输出: "s'teL ekat edoCteeL tsetnoc" 
//    注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
//
//    Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
//    Example 1:
//    Input: "Let's take LeetCode contest"
//    Output: "s'teL ekat edoCteeL tsetnoc"
//    Note: In the string, each word is separated by single space and there will not be any extra space in the string.


class Solution{
public:
    // 方法1：遇到空格就翻转之前的单词，然后拼接到结果字符串之中
    string reverseWords1(string s) {
        int len = s.size();
        string temp = "", res = "";
        for( int i = 0; i <= len; i++ ) {
            if( s[i] == ' ' || s[i] == '\0' ) {
                reverse( temp.begin(), temp.end() ); // 翻转单词
                res += temp;
                res += s[i];    //拼上间隔符
                temp = "";
            } else {
                temp += s[i];   // 拼接单词
            }
        }
        return res;
    }


};
int main(){
    Solution s;
    string str = "Let's take LeetCode contest";
    cout << s.reverseWords(str) << endl;
    return 0;
}
