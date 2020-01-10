#include<iostream>
#include<string>
using namespace std;


//    「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
//
//    1.     1
//    2.     11
//    3.     21
//    4.     1211
//    5.     111221
//    1 被读作  "one 1"  ("一个一") , 即 11。
//    11 被读作 "two 1s" ("两个一"）, 即 21。
//    21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
//
//    给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
//
//    注意：整数序列中的每一项将表示为一个字符串。
//
//     
//
//    示例 1:
//
//    输入: 1
//    输出: "1"
//    示例 2:
//
//    输入: 4
//    输出: "1211"
//
//
//    The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//    1.     1
//    2.     11
//    3.     21
//    4.     1211
//    5.     111221
//    1 is read off as "one 1" or 11.
//    11 is read off as "two 1s" or 21.
//    21 is read off as "one 2, then one 1" or 1211.
//
//    Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
//    Note: Each term of the sequence of integers will be represented as a string.


class Solution {
public:
    // 方法1：用一个变量暂存上一项序列中正在统计的数，另一个变量记录统计结果，统计结果后将统计结果添加到当前序列
    string countAndSay(int n) {

        char currentNum;    // 上一项中当前正在统计的数
        int numCount;       // 上一项中当前正在统计的数的个数
        string res[n];
        res[0] = "1";
        for(int i = 1; i < n; ++i) {
            // 初始化
            currentNum = res[i - 1][0];
            numCount = 0;
            res[i] = "";
            // 遍历上一个字符串，统计数字个数并存下当前报数
            for(int j = 0; j < res[i - 1].size(); ++j) {
                if(res[i - 1][j] == currentNum) {
                    numCount++;
                } else {
                    res[i] += '0' + numCount;       // 将统计结果转换成字符并添加到当前项中
                    res[i] += currentNum;
                    currentNum = res[i - 1][j];
                    numCount = 0;
                    j--;
                }
                // 加上最后的统计，也可放在循环外部
                if( j == res[i - 1].size() - 1) {
                    res[i] += '0' + numCount;
                    res[i] += currentNum;
                    numCount = 0;
                }
            }
            //cout << res[i] << endl;

        }
        return res[n - 1];
    }
};
int main() {
    Solution s;
    cout << s.countAndSay(20) << endl;
    return 0;
}
