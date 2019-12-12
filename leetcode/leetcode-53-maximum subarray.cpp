#include<iostream>
#include<vector>
using namespace std;

//    给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//    示例:
//
//    输入: [-2,1,-3,4,-1,2,1,-5,4],
//    输出: 6
//    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
//    进阶:
//
//    如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
//
//    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.


class Solution {
public:
    // 方法1：有些类似 dp 的思想，当 sum <= 0 时，结束当前子序列，重新计算一个新序列（贪心法？）
    // 时间复杂度 O(n)
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            sum =  sum > 0 ? sum + nums[i] : nums[i]; //连续子序列的和，前面相加小于0，则可直接从nums[i]重新开始
            if(sum > res) {
                res = sum;
            }
        }
        return res;
    }
    // 方法2：正规的 dp
    // 时间复杂度 O(n)
    int maxSubArray2(vector<int>& nums) {
        int res = nums[0];
        int len = nums.size();
        vector<int> dp(len);   // dp[i] 表示 nums 中以 nums[i] 结尾的最大子序和
        dp[0] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
    return 0;

}
