#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 *
 * Example 1:
 *
 * Input: 6
 * Output: true
 * Explanation: 6 = 2 × 3
 * Example 2:
 *
 * Input: 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 * Example 3:
 *
 * Input: 14
 * Output: false
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 * Note:
 *
 * 1 is typically treated as an ugly number.
 * Input is within the 32-bit signed integer range: [−231,  231 − 1].
 */


class Solution {
public:

    // 方法1：迭代减小 num，并检查 num 是否满足条件 4ms 打败90%
    bool isUgly(int num) {
        if(num == 1){
            return true;
        }
        if(num <= 0){
            return false;
        }
        while(num > 1){
            if(num % 2 == 0){
                num /= 2;
            }else if(num % 3 == 0){
                num /= 3;
            }else if(num % 5 == 0){
                num /= 5;
            }else{
                return false;
            }
        }
        return num == 1;
    }


    // 方法2：先求丑数（由求丑数2想到的），直到丑数等于num，而当求出的丑数大于num时return false，效率很慢40ms，打败13%
    bool isUgly2(int num) {
        if(num == 1){
            return true;
        }
        if(num <= 0){
            return false;
        }
        vector<int> ugly_nums(1690, 1);
        int i2, i3, i5;                             // 分别指向 2, 3, 5需要乘的数
        i2 = i3 = i5 = 0;
        for(int i = 1; i < 1690; i++){
            int temp = min( min(ugly_nums[i2] * 2, ugly_nums[i3] * 3), ugly_nums[i5] * 5 );
            if(temp > num){
                return false;
            }else if(temp == num){
                return true;
            }else{
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

        }
        return false;
    }
};
int main(){
    Solution s;
    cout << s.isUgly(54) << endl;
    return 0;
}
