#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//    打家劫舍2
//
//    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
//    同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//    给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//    示例 1:
//    输入: [2,3,2]
//    输出: 3
//    解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
//
//    示例 2:
//    输入: [1,2,3,1]
//    输出: 4
//    解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//         偷窃到的最高金额 = 1 + 3 = 4 。

//
//    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
//    That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses
//    were broken into on the same night.
//    Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//    Example 1:
//    Input: [2,3,2]
//    Output: 3
//    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//                 because they are adjacent houses.
//    Example 2:
//    Input: [1,2,3,1]
//    Output: 4
//    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//                 Total amount you can rob = 1 + 3 = 4.




class Solution{
public:
    // 方法1：动态规划，将问题拆成偷最后一个房屋和不偷最后一个房屋，
    // 即 分别求 nums[0 ~ len - 2] 和 nums[1 ~ len - 1] 可偷到的最大金额
    // 设 dp(i) 表示偷到第 i 个房屋时已偷到的最高金额
    // dp(i) = max( dp(i - 2) + nums[i], dp(i - 1) )
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> dp1(len, 0);   // 忽略最后一个房屋的情况
        vector<int> dp2(len, 0);   // 忽略第一个房屋的情况

        // 求 dp1
        dp1[0] = nums[0];          // 下标与nums 保持一致
        dp1[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len - 1; ++i){
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }

        // 求 dp2
        dp2[0] = nums[1];          // 忽略 nums[0] 直接从 nums[1] 开始
        if(len > 2){               // 防止访问越界
           dp2[1] = max(nums[2], nums[1]);
        }
        for(int i = 2; i < len - 1; ++i){
            dp2[i] = max(dp2[i - 2] + nums[i + 1], dp2[i - 1]);
        }

        return dp1[len - 2] > dp2[len - 2] ? dp1[len - 2] : dp2[len - 2];
    }
    // 或
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> dp1(len, 0);        // 忽略最后一个房屋的情况
        vector<int> dp2(len, 0);        // 忽略第一个房屋的情况
        // 求 dp1
        dp1[1] = nums[0];               // dp[0] = 0，下标从 1 开始，nums[0] 是第1个房屋
        for(int i = 2; i < len; ++i){
            dp1[i] = max(dp1[i - 2] + nums[i - 1], dp1[i - 1]);
        }

        // 求 dp2
        dp2[1] = nums[1];               // dp[0] = 0，下标从 1 开始，因为忽略了 nums[0]，所以 nums[1] 是第1个房屋
        for(int i = 2; i < len; ++i){
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }
        return dp1[len - 1] > dp2[len - 1] ? dp1[len - 1] : dp2[len - 1];
    }
};
int main(){
    Solution s;

    return 0;
}
