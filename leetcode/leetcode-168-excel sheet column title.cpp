#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//    Excel 表列名称
//
//    给定一个正整数，返回它在 Excel 表中相对应的列名称。
//
//    例如，
//
//        1 -> A
//        2 -> B
//        3 -> C
//        ...
//        26 -> Z
//        27 -> AA
//        28 -> AB
//        ...
//    示例 1:
//
//    输入: 1
//    输出: "A"
//    示例 2:
//
//    输入: 28
//    输出: "AB"
//    示例 3:
//
//    输入: 701
//    输出: "ZY"
//
//
//    Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//    For example:
//
//        1 -> A
//        2 -> B
//        3 -> C
//        ...
//        26 -> Z
//        27 -> AA
//        28 -> AB
//        ...


class Solution {
public:
    // 方法1：其实就是十进制转 26 进制
    string convertToTitle(int n) {
        string res;
        while(n){
            int tmp = --n % 26;                         // --n 是为了用 [0, 25] 对应到 [A, Z]
            res = static_cast<char>('A' + tmp) + res;   // 将每一位转换成字符，不断插入到结果字符串的前面
            n /= 26;
        }
        return res;
    }
};


int main(){
    Solution s;

    return 0;
}
