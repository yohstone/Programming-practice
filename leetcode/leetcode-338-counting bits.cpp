#include<iostream>
using namespace std;

//编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
//
//Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
//
//Example 1:
//
//Input: 00000000000000000000000000001011
//Output: 3
//Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.




class Solution{
public:
    // 求从 0 ~ num 中，每个数的二进制中 1 的个数
    // 方法 1：暴力法，依次对每一个数调用 hamingWeightCore() 函数，求出该数二进制中 1 的个数
    // 时间复杂度 O(n^2)  空间复杂度 O(n) (用于存储结果)
    vector<int> countBits(int num) {
        vector<int> res;
        for(int n = 0; n <= num ; ++n){
            int cur_count = hamingWeightCore(n);      // 用于统计当前数字的二进制中 1 的个数
            res.push_back(cur_count);
        }
        return res;
    }

    // 求从 0 ~ num 中，每个数的二进制中 1 的个数
    // 方法 2：动态规划法 1
    // 奇数：二进制中，一个奇数一定比它前一个偶数多一个最低位的 1；
    // 偶数: 二进制中，一个偶数肯定和 它 / 2 之后的数的二进制 1 的个数相同。
    // 时间复杂度 O(n) 空间复杂度 O(n)
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);       // 0 的二进制中 1 的个数为 0
        for(int n = 1; n <= num ; ++n){
            if(n & 1 == 1){     // 奇数
                res.push_back(res[n - 1] + 1);
            }else{              // 偶数
                res.push_back(res[n / 2]);
            }
        }
        return res;
    }


    // 求 一个数 n 的二进制中 1 的个数
    // 使用 n = n & (n-1) 将 n 的最后一个 1  反转变为 0，当 n 为 0 时结束，反转了几次就有几个 1
    int hamingWeightCore(uint32_t n){
        int num = 0;

        while(n){
            num++;
            n &= n-1;
        }
        return num;
    }

};
int main(){
    return 0;
}
