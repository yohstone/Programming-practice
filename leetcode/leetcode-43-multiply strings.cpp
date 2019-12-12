#include<iostream>
#include<string>
using namespace std;

    // 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

    // 示例 1:

    // 输入: num1 = "2", num2 = "3"
    // 输出: "6"
    // 示例 2:

    // 输入: num1 = "123", num2 = "456"
    // 输出: "56088"
    // 说明：

    // num1 和 num2 的长度小于110。
    // num1 和 num2 只包含数字 0-9。
    // num1 和 num2 均不以零开头，除非是数字 0 本身。
    // 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。


    // Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

    // Example 1:

    // Input: num1 = "2", num2 = "3"
    // Output: "6"
    // Example 2:

    // Input: num1 = "123", num2 = "456"
    // Output: "56088"
    // Note:

    // The length of both num1 and num2 is < 110.
    // Both num1 and num2 contain only digits 0-9.
    // Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    // You must not use any built-in BigInteger library or convert the inputs to integer directly.



class Solution {
public:
    // 方法1：模仿乘法竖式进行计算
    // 时间复杂度 O(m*n) 俩数的长度积 
    // 空间复杂度 O(m+n) 俩数的长度和，用于存储计算结果
    string multiply(string num1, string num2) {
        string res = "0";
        if(num1 == "0" || num2 == "0"){
            return res;
        }
        int len1 = num1.size();
        int len2 = num2.size();
        for(int p2 = len2 - 1; p2 >= 0; --p2){        // 用 num2 的每一位去乘 num
            string res_tmp = "";                      // 用于暂存每一位的相乘结果
            for(int i = 0; i < len2 - 1 - p2; ++i){   // 给每一位的乘积结果后加上'0'
                res_tmp.append("0");
            }
            int digit2 = num2[p2] - '0';              // 将 num2 的当前位转换成数字 digit2
            int carry = 0;
            for(int p1 = len1 - 1; p1 >= 0 || carry > 0; --p1){ // 计算 digit2 与 num2 每一位的乘积
                int digit1 = p1 >= 0 ? num1[p1] - '0' : 0;      // 将 num1 的当前位数转换成数字
                int product = digit2 * digit1 + carry;          // 乘积
                res_tmp.insert(res_tmp.begin(), '0' + product % 10);
                carry = product / 10;
            }
            res = addStrings(res, res_tmp);
        }
        return res;
        
    }
    // 返回两个字符串的和
    string addStrings(string num1, string num2) {
        int carry = 0; // 进位
        string res = "";
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        for(;p1 >= 0 || p2 >= 0 || carry != 0; p1--, p2-- ){
            int sum = 0;
            sum += p1 >= 0 ? num1[p1] - '0' : 0;   // 加 num1 的当前位或 0
            sum += p2 >= 0 ? num2[p2] - '0' : 0;   // 加 num2 的当前位或 0
            sum += carry;                          // 加 进位
            carry = sum / 10;
            res.insert(res.begin(), '0' + sum % 10);
        }
        return res;
    }


    // 方法2：优化版乘法竖式
    // num1 的第 i 位 乘以 num2 的第 j 位的结果 xy (x 可能为0)，x 是结果 res[i + j] 的一个加数，y 是结果的第 i+j+1 位，即 res[i + j + 1]的一个加数
    // 时间复杂度 O(m*n) 比方法1稍快
    // 空间复杂度 O(m+n) 
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int len1 = num1.size();
        int len2 = num2.size();
        string res(len1 + len2, '0');
        for(int p2 = len2 - 1; p2 >= 0; --p2){        // 用 num2 的每一位去乘 num       
            int digit2 = num2[p2] - '0';              // 将 num2 的当前位转换成数字 digit2
            for(int p1 = len1 - 1; p1 >= 0 ; --p1){   // 计算 digit2 与 num2 每一位的乘积
                int digit1 = num1[p1] - '0';          // 将 num1 的当前位数转换成数字
                int product = digit2 * digit1 + (res[p1 + p2 + 1] - '0');          // 乘积
                res[p1 + p2 + 1] = '0' + product % 10;
                res[p1 + p2]     = '0' + (res[p1 + p2] - '0' +  product / 10);
            }
        }
        int i = 0;
        for(; i < res.size(); ++i){                   // 检查字符串前面有几个 '0'
            if(res[i] == '0'){
                continue;
            }else{
                break;
            }
        }
        return res.substr(i);                         // 返回删去前面 '0' 的子字符串
        
    }

};


int main(){
    
    return 0;
}
