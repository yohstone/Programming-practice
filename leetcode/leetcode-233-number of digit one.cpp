#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
using namespace std;

//    给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
//
//    示例:
//
//    输入: 13
//    输出: 6
//    解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
//
//    Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
//
//    Example:
//
//    Input: 13
//    Output: 6
//    Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.


class Solution {
public:
    // 方法1: 先统计最高位为 1 的个数，再 统计其他位为 1 的个数
    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }
        int len = getLen(n);
        if(len == 1) {
            return 1;
        }
        int digits = pow(10, len - 1);  // 1 0000..  即位数（长度）为 len 的最小整数
        int first = n / digits;
        int firstOne = first == 1 ? n % digits + 1 : digits; // 如果首位是 1 则 1 的数量 = 首位之后的剩余部分 + 1 ，否则大于 1 时就贡献了 1000.. 个1
        int otherOne = first * (len - 1) * (digits / 10);
        return firstOne + otherOne + countDigitOne(n % digits);
    }

    // 求 n 的位数（长度）
    int getLen(int n) {
        int len = 0;
        while(n) {
            ++len;
            n /= 10;
        }
        return len;
    }


};

int main(){
    return 0;
}
