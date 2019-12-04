#include<iostream>
#include<string>
using namespace std;

//    给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//    输入为非空字符串且只包含数字 1 和 0。
//
//    示例 1:
//
//    输入: a = "11", b = "1"
//    输出: "100"
//    示例 2:
//
//    输入: a = "1010", b = "1011"
//    输出: "10101"
//
//    Given two binary strings, return their sum (also a binary string).
//
//    The input strings are both non-empty and contains only characters 1 or 0.
//
//    Example 1:
//
//    Input: a = "11", b = "1"
//    Output: "100"
//    Example 2:
//
//    Input: a = "1010", b = "1011"
//    Output: "10101"


class Solution {
public:
    // 方法：直接从两个字符串尾部开始遍历相加，计算和与进位
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0, sum;  // 每一位的进位与和
        int i = a.length() - 1, j = b.length() - 1;
        while( i >= 0  || j >= 0 || carry ) {
            char c;
            int x = 0, y = 0;
            if( i >= 0)
                x = a[i--] - '0';
            if(j >= 0)
                y = b[j--] - '0';
            sum = x + y + carry;
            c = '0' + sum % 2;
            res = c + res;
            carry = sum / 2;
        }
        return res;
    }
};
int main() {
    Solution s;
    char a[128], b[128];
    while(scanf("%s %s", a, b) == 2) {
        cout << s.addBinary(a, b) << endl;
    }

    return 0;

}

