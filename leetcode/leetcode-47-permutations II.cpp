#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//    给定一个可包含重复数字的序列，返回所有不重复的全排列。
//
//    示例:
//
//    输入: [1,1,2]
//    输出:
//    [
//      [1,1,2],
//      [1,2,1],
//      [2,1,1]
//    ]
//
//    Given a collection of numbers that might contain duplicates, return all possible unique permutations.




class Solution {
public:

    // 方法1：回溯法，先排序，根据排序结果判断数是否重复，同时使用一个数组记录每个数是否已使用；
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> track;      // 用于暂存每种排列
        vector<bool> isUsed(nums.size(), false);    // 用于记录每个数是否已使用
        sort(nums.begin(), nums.end());// 先排序

        backtrack(nums, track, isUsed);
        return res;
    }
    void backtrack(vector<int> &nums, vector<int> &track, vector<bool> &isUsed){
        if(track.size() == nums.size()){    // 结束条件，一种排列已经结束
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(isUsed[i]){                  // 排除不合法选择，即若该数已使用，则跳过
                continue;
            }
            if(i > 0 && nums[i] == nums[i - 1] && isUsed[i - 1]){// 是重复的数，且该重复数已使用，则跳过
                continue;
            }
            track.push_back(nums[i]);
            isUsed[i] = true;
            backtrack(nums, track, isUsed);
            track.pop_back();
            isUsed[i] = false;
        }
    }


};


int main(){

    return 0;
}
