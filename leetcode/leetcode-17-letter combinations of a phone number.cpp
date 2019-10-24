#include<iostream>
using namespace std;

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//示例:
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//说明:
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
//
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//
//Although the above answer is in lexicographical order, your answer could be in any order you want.



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
