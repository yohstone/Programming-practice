#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//    给定一个没有重复数字的序列，返回其所有可能的全排列。
//
//    示例:
//
//    输入: [1,2,3]
//    输出:
//    [
//      [1,2,3],
//      [1,3,2],
//      [2,1,3],
//      [2,3,1],
//      [3,1,2],
//      [3,2,1]
//    ]
//
//    Given a collection of distinct integers, return all possible permutations.



class Solution {
public:
    // 方法1：回溯法
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;   // 用于暂存每种排列
        backtrack(nums, track);
        return res;
    }
    void backtrack(vector<int> &nums, vector<int> &track){
        if(track.size() == nums.size()){    // 结束条件，一种排列已经结束
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(find(track.begin(), track.end(), nums[i]) != track.end()){   // 排除不合法的选择，跳过已使用的数
                // 也可以使用 isUsed 数组记录已使用过的数，以空间换时间
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }

    // 方法1：回溯法，优化版，直接在 nums 上交换数据产生每种排列
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int i){
        if(i == nums.size()){    // 结束条件，一种排列已经结束
            res.push_back(nums);
            return;
        }
        for(int j = i; j < nums.size(); ++j){
            if(j != i){
                swap(nums[i], nums[j]);
            }
            backtrack(nums, res, i + 1);
            if(j != i){
                swap(nums[i], nums[j]);
            }
        }
    }


};


int main(){

    return 0;
}
