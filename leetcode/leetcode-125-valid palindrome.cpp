#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

    // 验证回文串
    // 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

    // 说明：本题中，我们将空字符串定义为有效的回文串。

    // 示例 1:

    // 输入: "A man, a plan, a canal: Panama"
    // 输出: true
    // 示例 2:

    // 输入: "race a car"
    // 输出: false

    // Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    // Note: For the purpose of this problem, we define empty string as valid palindrome.



class Solution {
public:
    // 方法1：使用首尾指针遍历字符串进行对比
    // 使用了标准库<cctype>里的两个函数：
    // isalnum(c) : 当 c 为字母或数字时为真
    // isdigit(c) : 当 c 为数字时为真
    bool isPalindrome(string s) {
        int len = s.size();
        if(len <= 1){
            return true;
        }
        int head = 0;       // 首指针
        int tail = len - 1; // 尾指针
        while(head < tail){
            auto head_isalnum = isalnum(s[head]);
            auto tail_isalnum = isalnum(s[tail]);
            if(!head_isalnum){// 首指针指向的是非数字或非字母
                ++head;
                continue;
            }Å
            if(!tail_isalnum){// 尾指针指向的是非数字或非字母
                --tail;
                continue;
            }
            if(head_isalnum && tail_isalnum){ // 都是数字或字母
                if(s[head] == s[tail] || 
                ( !isdigit(s[head]) && !isdigit(s[tail]) && abs(s[head] - s[tail]) == 32 )){
                    ++head;
                    --tail;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {

    return 0;
}
