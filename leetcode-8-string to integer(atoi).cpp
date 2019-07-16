#include<iostream>
#include<string>
#include<sstream>
using namespace std;

/* Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 *
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
 * Example 1:
 *
 * Input: "42"
 * Output: 42
 * Example 2:
 *
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus sign.
 *              Then take as many numerical digits as possible, which gets 42.
 * Example 3:
 *
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 * Example 4:
 *
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a numerical
 *              digit or a +/- sign. Therefore no valid conversion could be performed.
 * Example 5:
 *
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 *              Thefore INT_MIN (−2^31) is returned.
 */


class Solution{
public:
    // 方法1，一个个字符判断，然后累加数字
    int myAtoi(string str){
        int len = str.length();
        bool isFirst  = true;       // 是否是第一个非空白符
        bool isMinus  = false;      // 是否是负数
        long long res = 0;
        for(int i = 0; i < len; i++){
            if(str[i] == ' ' && isFirst){                              // 跳过前面的空格
                continue;
            }else if(str[i] == '-' && isFirst){                        // 开头为 '-' 表示为负数
                isMinus = true;
                isFirst = false;
            }else if(str[i] == '+' && isFirst){                        // 正数
                isFirst = false;
                continue;
            }else if(str[i] >= '0' && str[i] <= '9'){                  // 累加算结果
                res = res * 10 + (str[i] - '0');
                if( res > INT_MAX){                                    // 若累加结果超范围，返回边界值
                    return isMinus ? INT_MIN : INT_MAX;
                }
                isFirst =false;
            }else if( (str[i] < '0' || str[i] > '9') && !isFirst){     // 遇到后面的非有效字符，结束循环
                break;
            }else{
                return 0;
            }
        }
        return isMinus ? -res : res;
    }

    // 方法2： 使用stringstream来读取数字
    int myAtoi2(string str){
        while(*str.begin() == ' '){     // 删除前面的空格
            str.erase(str.begin());
        }
        if(str == ""){                       // 空字符串
            return 0;
        }
        stringstream ss;
        ss << str;
        int n;
        ss >> n;
        return n;
    }
};
int main(){
    string str = "214748364867867867867867867";
    Solution s;
    cout <<  s.myAtoi2(str) << endl;
    return 0;
}
