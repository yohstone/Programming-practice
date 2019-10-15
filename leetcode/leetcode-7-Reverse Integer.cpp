#include<iostream>
#include<climits>
using namespace std;

/* Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 * Input: 123
 * Output: 321
 * Example 2:
 *
 * Input: -123
 * Output: -321
 * Example 3:
 *
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * int: when take 4 bytes namely 32 bits it' range is  [-2147483648, 2147483647]
 */


class Solution {
public:
    // 方法1： 使用long long 存储翻转结果，从低位开始暴力遍历 x 的每一位，直接进行翻转
    int reverse(int x) {
        long long rev = 0;
        while(x != 0) {
            int digit = x % 10;                     // 取x的每一位
            rev = rev * 10 + digit;
            if(rev > INT_MAX || rev < INT_MIN) {    // 溢出时返回 0
                return 0;
            }
            x = x / 10;
        }
        return rev;
    }

    //方法2：不使用long long，在结果将溢出之前就判断下一次计算是否会溢出
    int reverse2(int x) {
        int rev = 0;
        while(x != 0) {
            int digit = x % 10;                     // 取x的每一位
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))    // 正数溢出的判断，使用 int 的 最大值/10，及最大值的个位数字进行判断
                return 0;
            if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))   // 负数溢出的判断，使用 int 的 最小值/10，及最小值的个位数字进行判断
                return 0;
            rev = rev * 10 + digit;
            x = x / 10;
        }
        return rev;
    }

};
int main() {
    Solution s;
    cout << s.reverse2(-2143847412);
    return 0;
}
