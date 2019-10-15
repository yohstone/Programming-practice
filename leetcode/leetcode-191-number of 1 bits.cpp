#include<iostream>
using namespace std;

/* Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
 *
 *
 * Example 1:
 *
 * Input: 00000000000000000000000000001011
 * Output: 3
 * Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
 */



class Solution{
public:
    // 方法1：循环变量里n的每一位，统计1的个数
    int hamingWeight(uint32_t n){
        int num = 0;
        while(n){
            if( n & 1 ){
                num++;
            }
            n = n >> 1;
        }
        return num;
    }

    // 方法2：使用 n = n & (n-1) 将n的最后一个1反转变为0，当n为0时结束，反转了几次就有几个1
    int hamingWeight(uint32_t n){
        int num = 0;

        while(n){
            num++;
            n &= n-1;
        }
        return num;
    }
    // 方法3 使用bitset库的函数
    int hammingWeight(uint32_t n) {
        bitset<32> tmp = n;
        int num = tmp.count(); // count()函数统计n的二进制中1的个数并返回
        return num;
    }


};
int main(){
    return 0;
}
