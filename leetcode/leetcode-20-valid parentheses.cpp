#include<iostream>
#include<string>
using namespace std;

//    # 有效的括号，即括号匹配
//
//    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//    有效字符串需满足：
//
//    左括号必须用相同类型的右括号闭合。
//    左括号必须以正确的顺序闭合。
//    注意空字符串可被认为是有效字符串。
//
//    示例 1:
//
//    输入: "()"
//    输出: true
//    示例 2:
//
//    输入: "()[]{}"
//    输出: true
//    示例 3:
//
//    输入: "(]"
//    输出: false
//    示例 4:
//
//    输入: "([)]"
//    输出: false
//    示例 5:
//
//    输入: "{[]}"
//    输出: true
//
//    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//    An input string is valid if:
//
//    Open brackets must be closed by the same type of brackets.
//    Open brackets must be closed in the correct order.
//    Note that an empty string is also considered valid.
//
//    Example 1:
//
//    Input: "()"
//    Output: true
//    Example 2:
//
//    Input: "()[]{}"
//    Output: true
//    Example 3:
//
//    Input: "(]"
//    Output: false
//    Example 4:
//
//    Input: "([)]"
//    Output: false
//    Example 5:
//
//    Input: "{[]}"
//    Output: true


class Solution {
public:
    // 方法：将字符串中的左括号 ( [ { 压入栈中，当遇到右括号时与栈顶的左括号匹配，若匹配则继续，否则结束
    bool isValid(string s) {
        int rear = 1;
        int len = s.length();
        char st[len + 2]; //stack
        for(int i = 0; i < len; i++) {
            if(s[i] == ')' && st[rear - 1] != '(') {
                return false;
            } else if(s[i] == ']' && st[rear - 1] != '[') {
                return false;
            } else if(s[i] == '}' && st[rear - 1] != '{') {
                return false;
            } else if(s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
                st[rear++] = s[i];
            } else {
                rear--;
            }
        }
        if(rear == 1)
            return true;
        else
            return false;
    }
};
int main() {
    Solution s;
    string str;
    while(cin >> str) {
        cout << s.isValid(str) << endl;
    }
    return 0;
}
