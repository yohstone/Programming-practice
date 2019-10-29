#include<iostream>

//    给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//
//    返回被除数 dividend 除以除数 divisor 得到的商。
//
//    示例 1:
//
//    输入: dividend = 10, divisor = 3
//    输出: 3
//    示例 2:
//
//    输入: dividend = 7, divisor = -3
//    输出: -2
//    说明:
//
//    被除数和除数均为 32 位有符号整数。
//    除数不为 0。
//    假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
//
//    Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//    Return the quotient after dividing dividend by divisor.
//
//    The integer division should truncate toward zero.
//
//    Example 1:
//
//    Input: dividend = 10, divisor = 3
//    Output: 3
//    Example 2:
//
//    Input: dividend = 7, divisor = -3
//    Output: -2
//    Note:
//
//    Both dividend and divisor will be 32-bit signed integers.
//    The divisor will never be 0.
//    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.


using namespace std;
class Solution {
public:
    // 方法1：用减法求商，时间复杂度太大，没有AC
    int divide(int dividend, int divisor) {
        if( dividend == 0) return 0;
        if(divisor == 1) return dividend;

        long long res = 0;
        bool isMinus = false; // 结果是否是负数标记

        if(dividend < 0 && divisor < 0){
            isMinus = false;
        }else if(dividend < 0 || divisor < 0){
            isMinus = true;
        }
        unsigned int dividend_temp = dividend == INT_MIN ? (unsigned int) (INT_MAX) + 1:abs(dividend);
        unsigned int divisor_temp = divisor == INT_MIN ? (unsigned int) (INT_MAX) + 1:abs(divisor);

        while(dividend_temp >= divisor_temp){  // 求无符号的商
            ++res;
            dividend_temp = dividend_temp - divisor_temp;

        }

        if(res > INT_MAX || -res < INT_MIN){
            return INT_MAX;
        }

        return isMinus ? -res : res;
    }

    // 方法2：列竖式求除法，除数 divisor 左移直到大于被除数 dividend
    int divide(int dividend, int divisor) {
        if( dividend == 0) return 0;
        if(divisor == 1) return dividend;

        long long res = 0;
        bool isMinus = false; // 结果是否是负数标记

        if(dividend < 0 && divisor < 0){
            isMinus = false;
        }else if(dividend < 0 || divisor < 0){
            isMinus = true;
        }
        unsigned int dividend_temp = dividend == INT_MIN ? (unsigned int) (INT_MAX) + 1:abs(dividend);
        unsigned int divisor_temp = divisor == INT_MIN ? (unsigned int) (INT_MAX) + 1:abs(divisor);

        while(dividend_temp >= divisor_temp){
            unsigned int temp = divisor_temp, mask = 1;
            while(temp && dividend_temp >= temp){
                dividend_temp -= temp;
                res += mask;
                mask <<= 1;
                temp <<= 1;
            }
        }

        if(res > INT_MAX || -res < INT_MIN){
            return INT_MAX;
        }

        return isMinus ? -res : res;
    }
};
int main(){
    Solution s;
    while(1){
        int dividend, divisor;
        cin >> dividend >> divisor;
        cout << s.divide(dividend, divisor) << endl;
    }
    return 0;
}
