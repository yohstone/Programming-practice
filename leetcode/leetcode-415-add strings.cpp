#include<iostream>
#include<string>
using namespace std;

    // 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

    // 注意：

    // num1 和num2 的长度都小于 5100.
    // num1 和num2 都只包含数字 0-9.
    // num1 和num2 都不包含任何前导零。
    // 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

    // Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

    // Note:

    // The length of both num1 and num2 is < 5100.
    // Both num1 and num2 contains only digits 0-9.
    // Both num1 and num2 does not contain any leading zero.
    // You must not use any built-in BigInteger library or convert the inputs to integer directly.



class Solution {
public:
    // 方法1：设置两个指针指向 num1 和 num2 的尾部，模拟加法竖式
    string addStrings(string num1, string num2) {
        int carry = 0; // 进位
        string res = "";
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        while(p1 >= 0 || p2 >= 0 || carry != 0 ){
            int sum;
            if(p1 >= 0 && p2 >= 0){
                sum = num1[p1] - '0' + num2[p2] - '0' + carry;
            }else if(p1 >= 0){
                sum = num1[p1] - '0' + carry;
            }else if(p2 >= 0){
                sum = num2[p2] - '0' + carry;
            }else{
                sum = carry;
            }
            carry = sum / 10;
            char tmp = '0' + sum % 10;
            res = tmp + res;
            --p1;
            --p2;
        }
        return res;
    }
};

int main(){

}
