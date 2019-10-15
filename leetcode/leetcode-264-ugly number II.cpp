#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 *
 * Example:
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * Note:  
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 */


class Solution {
public:

    // 方法1：涉及动态规划，当前状态依赖前3个状态，用一个 vector ugly_nums存储 n 之前所有丑数的集合，最后返回ugly_nums[n-1]
    // 时间复杂度 O(n)， 12ms, 打败81%
    int nthUglyNumber(int n) {
        if(n == 1){
            return 1;
        }
        vector<int> ugly_nums(n, 1);
        int i2, i3, i5;                             // 分别指向 2, 3, 5需要乘的数
        i2 = i3 = i5 = 0;
        for(int i = 1; i < n; i++){
            int temp = min( min(ugly_nums[i2] * 2, ugly_nums[i3] * 3), ugly_nums[i5] * 5 );
            ugly_nums[i] = temp;
            if(temp == ugly_nums[i2] * 2){
                i2++;
            }
            if(temp == ugly_nums[i3] * 3){          // 只能用 if ，因为各个结果可能相同，相同时都需要++
                i3++;
            }
            if(temp == ugly_nums[i5] * 5){
                i5++;
            }
        }
        return ugly_nums[n-1];
    }
};
int main(){
    Solution s;
    cout << s.nthUglyNumber(1690) << endl;
    return 0;
}
