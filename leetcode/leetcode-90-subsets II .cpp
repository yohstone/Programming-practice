#include<iostream>
#include<vector>
using namespace std;

//    给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//    说明：解集不能包含重复的子集。
//
//    示例:
//
//    输入: [1,2,2]
//    输出:
//    [
//      [2],
//      [1],
//      [1,2,2],
//      [2,2],
//      [1,2],
//      []
//    ]
//
//    Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
//    Note: The solution set must not contain duplicate subsets.


class Solution {
public:
    // 方法1：回溯法， 从第一个数开始遍历，递归遍历完包含当前数字的所有情况，
    //              然后从集合 cur_set 中删掉当前数字，再遍历下一数字
    // 为了防止出现重复的子集，使用 set 容器来暂存子集结果，并对每个子集排序
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> res_tmp;           // 使用 set 暂存结果，防止重复
        vector<int> cur_set;
        sort(nums.begin(), nums.end());     // 排序，防止重复

        backtrack(0, res_tmp, cur_set, nums);

        set<vector<int>>::iterator iter;
        for(iter = res_tmp.begin(); iter != res_tmp.end(); ++iter){ // 将子集结果取出放入结果数组中
            res.push_back(*iter);
        }
        return res;

    }
    void backtrack(int cur_i, set<vector<int>> &res_tmp, vector<int> &cur_set, vector<int> &nums){
        res_tmp.insert(cur_set);
        for(int j = cur_i; j < nums.size(); ++j){
//            if(j > cur_i && nums[j] == nums[j - 1]){
//                continue;               // 跳过重复的递归
//            }
            cur_set.push_back(nums[j]);
            backtrack(j + 1, res_tmp, cur_set, nums);
            cur_set.pop_back();
        }
    }
};
int main() {
    Solution s;

    return 0;
}
