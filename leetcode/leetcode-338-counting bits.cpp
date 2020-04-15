#include<iostream>
using namespace std;

    // 338. 比特位计数

    // 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

    // 示例 1:

    // 输入: 2
    // 输出: [0,1,1]
    // 示例 2:

    // 输入: 5
    // 输出: [0,1,1,2,1,2]
    // 进阶:

    // 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
    // 要求算法的空间复杂度为O(n)。
    // 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

    // Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

    // Example 1:

    // Input: 2
    // Output: [0,1,1]






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
