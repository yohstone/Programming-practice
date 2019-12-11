#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
using namespace std;

//    给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
//
//    示例:
//
//    输入: 13
//    输出: 6
//    解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
//
//    Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
//
//    Example:
//
//    Input: 13
//    Output: 6
//    Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.


class Solution {
public:
    // 方法1: 先统计最高位为 1 的个数，再 统计其他位为 1 的个数
    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }
        int len = getLen(n);
        if(len == 1) {
            return 1;
        }
        int digits = pow(10, len - 1);  // 1 0000..  即位数（长度）为 len 的最小整数
        int first = n / digits;
        int firstOne = first == 1 ? n % digits + 1 : digits; // 如果首位是 1 则 1 的数量 = 首位之后的剩余部分 + 1 ，否则大于 1 时就贡献了 1000.. 个1
        int otherOne = first * (len - 1) * (digits / 10);
        return firstOne + otherOne + countDigitOne(n % digits);
    }

    // 求 n 的位数（长度）
    int getLen(int n) {
        int len = 0;
        while(n) {
            ++len;
            n /= 10;
        }
        return len;
    }

//  方法2：总结规律数学法1
//    将数字分为 preNum, curNum, sufNum (后缀)。
//    1.计算千位出现1的次数：
//    preNumber = 0
//    curNumber = 2
//    sufNumber = 104
//    此时curNumber > 1,那么当千位为1时，即1***，可能出现1的次数有1000次(1000 ~ 1999)。此时preNumber = 0，不能借位所以只有这一种情况出现。即千位出现1的次数为1000
//
//    2.计算百位出现1的次数:
//    preNumber = 2
//    curNumber = 1
//    sufNumber = 4
//    此时curNumber = 1,那么当百位为1时，即1**，可能出现是次数:
//    我们发现现在preNumber = 2,此时百位可向前面借位
//    那么在不借位的情况下即21**可能会出现的情况为(2100->2104)，次数就是sufNumber + 1 即4 + 1 = 5
//    当向前面借位时就可能出现的情况为(*100->*199),我们发现每借位一次就有100中情况，总共有preNumber * 100中情况
//    不借位加上借位的情况出现的次数就是（4 + 1）+ 2 * 100 = 205
//
//    3.计算十位出现1的次数
//    preNumber = 21
//    currentNumber = 0
//    sufNumber = 4
//    此时curNumber < 1,若此时十位要出现1，肯定需要向前面借位，每次借位出现1的情况为(**10->**19)，也就是10
//    总共出现的1情况就是，preNumber * 10 = 21 * 10 = 210
//
//    4.计算个位出现1的次数
//    preNumber = 210
//    curNumber = 4
//    sufNumber = 0
//    此时curNumber >1 ,而且可向前借位，在不借位的情况下，各位1出现的次数为(2101)只有一次，
//    在借位的情况下为（***1）只有一种，可借位210次
//    总共出现1的情况为1 + 210 * 1 = 211
//
//    全部位加起来为1000 + 205 + 210 + 211 = 1626
//
//    可总结出公式为：
//    digits 为位数，即千位时 digits = 1000
//    sum为当前位数出现1的次数
//    当curNumber > 1 时：
//    sum = digits + digits * preNumber
//    当curNumber = 1 时：
//    sum = sufNumber + 1 + digits * preNumber
//    当curNumber < 1 时:
//    sum = digits * preNumber

//  若要改为统计数字 m 在 1 ~ n 中出现的次数，只需将下面的 if 判断语句中的 '1' 修改为 m 即可
    int countDigitOne2(int n) {
        if(n < 1){
            return 0;
        }
        int sum = 0;
        long long digits = 1;  // x 位数的最小值，即 digits = 10 ^ x
        while(digits <= n){
            int suf_num = n % digits;                   // 后缀数字（剩下的数字）
            int cur_num = n % (digits * 10) / digits;   // 当前位数上的数字
            int pre_num = n / (digits * 10);            // 前置数字
            if(cur_num > 1){                            // 可将 1 修改为其他需要统计的数字
                sum += digits + digits * pre_num;
            }else if(cur_num == 1){                     // 可将 1 修改为其他需要统计的数字
                sum += suf_num + 1 + digits * pre_num;
            }else{
                sum += digits * pre_num;
            }
            digits *= 10;
        }
        return sum;
    }


    // 方法3: 总结规律数学法2，官方
    // 将 i 从 1 遍历到 n，每次遍历 ii扩大 10 倍：
    // (n / ( i * 10 ) ) * i 表示 ( i * 10 ) 位上的 '1' 的个数
    // min( max ( ( n % ( i * 10 ) ) - i + 1, 0 ), i ) 表示需要额外计算的 ( i * 10 ) 位上 '1' 的个数
    int countDigitOne3(int n) {
        int countr = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return countr;
    }
};

int main(){
    return 0;
}
