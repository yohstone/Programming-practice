#include<iostream>
using namespace std;
/* Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 * Example 1:
 *
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 *
 * Input: a = -2, b = 3
 * Output: 1
 */

 class Solotion{
 public:
     // 先a与b异或，结果与无进位的和相等，再a与b按位与，得到进位，然后俩结果再异或，直到按位与的结果为0，可得到答案，

     // 方法1：递归
     int getSum(int a, int b){
        unsigned int andRes = a & b;
        int sum = a ^ b;
        if(andRes != 0){
            andRes = andRes << 1;
            return getSum(sum, andRes);
        }
        return sum;
     }

     // 方法2：迭代
     int getSum2(int a, int b) {
        int sum;
        unsigned int andRes = a & b;
        int xorRes = a ^ b;
        sum = andRes ^ xorRes;

        while(andRes != 0){
            andRes = andRes << 1;
            sum    = xorRes ^ andRes;
            andRes = xorRes & andRes;//看看两结果相加是否还有进位
            xorRes = sum;
        }
        return sum;
    }
 };
