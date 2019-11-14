#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//    打家劫舍
//
//    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//    给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//    示例 1:
//    输入: [1,2,3,1]
//    输出: 4
//    解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//         偷窃到的最高金额 = 1 + 3 = 4 。
//
//    示例 2:
//    输入: [2,7,9,3,1]
//    输出: 12
//    解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//         偷窃到的最高金额 = 2 + 9 + 1 = 12 。
//
//    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that
//    adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//    Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//    Example 1:
//    Input: [1,2,3,1]
//    Output: 4
//    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//                 Total amount you can rob = 1 + 3 = 4.
//
//    Example 2:
//    Input: [2,7,9,3,1]
//    Output: 12
//    Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//                 Total amount you can rob = 2 + 9 + 1 = 12.


class Solution{
public:
    // 方法1：动态规划
    // 设 dp(i) 表示偷到第 i 个房屋时已偷到的最高金额
    // dp(i) = max( dp(i - 2) + nums[i], dp(i - 1) )
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> dp(len, 0);
        dp[0] = nums[0];           // 下标与nums 保持一致
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; ++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[len - 1];
    }
    // 或
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> dp(len + 1, 0);
        dp[1] = nums[0];             // dp[0] = 0，下标从 1 开始，nums[0] 是第1个房屋
        for(int i = 2; i <= len; ++i){
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[len];
    }
};
int main(){
    Solution s;

    return 0;
}
