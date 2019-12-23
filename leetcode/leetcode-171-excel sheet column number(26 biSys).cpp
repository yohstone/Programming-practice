#include<iostream>
#include<string>

using namespace std;


//    给定一个Excel表格中的列名称，返回其相应的列序号。
//
//    例如，
//
//        A -> 1
//        B -> 2
//        C -> 3
//        ...
//        Z -> 26
//        AA -> 27
//        AB -> 28
//        ...
//    示例 1:
//
//    输入: "A"
//    输出: 1
//    示例 2:
//
//    输入: "AB"
//    输出: 28
//    示例 3:
//
//    输入: "ZY"
//    输出: 701
//
//    Given a column title as appear in an Excel sheet, return its corresponding column number.
//


class Solution {
public:
    // 方法：26进制转换，从头遍历字符串 s 转换
    int titleToNumber(string s) {
        int len = s.size();
        int res = 0;
        for(int i = 0; i < len; ++i){
            res = res * 26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};


int main(){
    Solution s;
    return 0;
}
