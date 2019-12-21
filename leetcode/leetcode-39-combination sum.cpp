#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//    给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//    candidates 中的数字可以无限制重复被选取。
//
//    说明：
//
//    所有数字（包括 target）都是正整数。
//    解集不能包含重复的组合。 
//    示例 1:
//
//    输入: candidates = [2,3,6,7], target = 7,
//    所求解集为:
//    [
//      [7],
//      [2,2,3]
//    ]
//    示例 2:
//
//    输入: candidates = [2,3,5], target = 8,
//    所求解集为:
//    [
//      [2,2,2,2],
//      [2,3,3],
//      [3,5]
//    ]
//    Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//    The same repeated number may be chosen from candidates unlimited number of times.
//
//    Note:
//
//    All numbers (including target) will be positive integers.
//    The solution set must not contain duplicate combinations.



class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;

public:
    // 方法1 ： 回溯法
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // x先将候选数组排序，以实现剪枝
        this->candidates = candidates;
        DFS(0, target);

        return res;

    }
    void DFS(int start, int target) {
        int len = candidates.size();
        if (target == 0) {
            res.push_back(path);
            return ;
        }
        for (int i = start; i < len && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);      // 选择当前 candidates[i]
            DFS(i, target - candidates[i]);
            path.pop_back();                    // 恢复上一状态
        }
    }
};
int main(){
    Solution s;

    return 0;
}
