#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

/* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * Example 1:
 *
 * Input: [3,0,1]
 * Output: 2
 * Example 2:
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 */


class Solution {
public:
    // 方法1 用0~n所有数的和减去nums中所有数之和就是缺少的那个数
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = 0; // nums中数的和
        int sum2;    // 0~n 所有数之和
        sum2 = len*( 1 + len ) / 2;
        for(int i=0; i<len; i++){
            sum += nums[i];
        }
        return sum2 - sum;
    }
    // 方法2 抑或，因为相同的数抑或为0，0~n 与数组nums的抑或结果为缺失的数
    int missingNumber2(vector<int>& nums) {
        int len = nums.size();
        int res = len; // i取不到len，所以设置初始为len，len即为最后的n
        for(int i=0; i<len; i++){
            res ^= i ^ nums[i];
        }
        return res;
    }

    // 方法3 先排序，然后找到大小相差不为1的两数
    int missingNumber3(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0] != 0) return 0;
        else if(nums[len-1] != len) return len;
        else{
            for(int i=0; i<len; i++){
                if( nums[i+1] - nums[i] != 1)
                    return nums[i]+1;
            }
        }
    }
    // 方法4 不用等差，边加i 边减nums[i]
    int missingNumber4(vector<int>& nums) {
        int len = nums.size();
        int sum = len; // i 为 0 ~ (n-1),循环会少加一个n
        for(int i=0; i<len; i++){
            sum = sum + i - nums[i];
        }
        return sum;
    }

};

int main(){
    Solution s;
    vector<int> nums = {9,6,4,2,3,5,7,0,1}; //{1,2,3,3,4,4,5};

    cout << s.missingNumber4(nums) << endl;
    return 0;
}
