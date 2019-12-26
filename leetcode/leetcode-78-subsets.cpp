#include<iostream>
#include<vector>
using namespace std;

    // 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
    // 说明：解集不能包含重复的子集。

    // 示例:
    // 输入: nums = [1,2,3]
    // 输出:
    // [
    //   [3],
    //   [1],
    //   [2],
    //   [1,2,3],
    //   [1,3],
    //   [2,3],
    //   [1,2],
    //   []
    // ]

    // Given a set of distinct integers, nums, return all possible subsets (the power set).
    // Note: The solution set must not contain duplicate subsets.


class Solution {
public:
    // 方法1：回溯法， 从第一个数开始遍历，递归遍历完包含当前数字的所有情况，
    //              然后从集合中删掉当前数字，再遍历下一数字
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur_set;
        backtrack(0, res, cur_set, nums);
        return res;
        
    }
    void backtrack(int cur_i, vector<vector<int>> &res, vector<int> &cur_set, vector<int> &nums){
        res.push_back(cur_set);
        for(int j = cur_i; j < nums.size(); ++j){
            cur_set.push_back(nums[j]);
            backtrack(j + 1, res, cur_set, nums);
            cur_set.pop_back();
        }
    }
};
int main() {
    Solution s;

    return 0;
}
