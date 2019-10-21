#include<iostream>
using namespace std;

//实现 pow(x, n) ，即计算 x 的 n 次幂函数。
//
//示例 1:
//
//输入: 2.00000, 10
//输出: 1024.00000
//示例 2:
//
//输入: 2.10000, 3
//输出: 9.26100
//示例 3:
//
//输入: 2.00000, -2
//输出: 0.25000
//解释: 2-2 = 1/22 = 1/4 = 0.25
//说明:
//
//-100.0 < x < 100.0
//n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
//
//Implement pow(x, n), which calculates x raised to the power n (xn).
//
//Example 1:
//
//Input: 2.00000, 10
//Output: 1024.00000
//Example 2:
//
//Input: 2.10000, 3
//Output: 9.26100
//Example 3:
//
//Input: 2.00000, -2
//Output: 0.25000
//Explanation: 2-2 = 1/22 = 1/4 = 0.25
//Note:
//
//-100.0 < x < 100.0
//n is a 32-bit signed integer, within the range [−231, 231 − 1]


class Solution {
public:
    // // 方法1：暴力法
    // double myPow(double x, int n) {
    //     long long N = n;
    //     double res = 1;
    //     if(n < 0){
    //         x = 1 / x;
    //         N = -N;
    //     }
    //     for(long long i = 0; i < N; ++i){
    //         res = res * x;
    //     }
    //     return res;
    // }
    // // 方法2：快速幂，递归实现
    // double myPow(double x, int n) {
    //     long long  N = n;
    //     if(n < 0){
    //         N = - N;
    //         x = 1 / x;
    //     }
    //     return fastPow(x, N);
    // }
    // double fastPow(double x, long long n){
    //     if(n == 0)
    //         return 1.0;
    //     double half = fastPow(x, n / 2);
    //     if(n % 2 == 0){
    //         return half * half;
    //     }else{
    //         return half * half * x;
    //     }
    // }
    // 方法3：快速幂，迭代实现
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
        
        long long  N = n;
        if(n < 0){
            N = - N;
            x = 1 / x;
        }
        return fastPow(x, N);
    }
    double fastPow(double x, long long n){
        double res = 1;
        double currProduct = x;
        long long temp = n;
        while(temp){
            if(temp & 1){   // n 的二进制中，第 i 位是1，则结果乘以 x^(2^i)
                res = res * currProduct;
            }
            currProduct = currProduct * currProduct;
            temp >>= 1;
        }
        return res;
    }
    
};
int main(){

    return 0;
}
