#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//    给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//    candidates 中的每个数字在每个组合中只能使用一次。
//
//    说明：
//
//    所有数字（包括目标数）都是正整数。
//    解集不能包含重复的组合。 
//    示例 1:
//
//    输入: candidates = [10,1,2,7,6,1,5], target = 8,
//    所求解集为:
//    [
//      [1, 7],
//      [1, 2, 5],
//      [2, 6],
//      [1, 1, 6]
//    ]
//    示例 2:
//
//    输入: candidates = [2,5,2,1,2], target = 5,
//    所求解集为:
//    [
//      [1,2,2],
//      [5]
//    ]
//
//    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//    Each number in candidates may only be used once in the combination.
//
//    Note:
//
//    All numbers (including target) will be positive integers.
//    The solution set must not contain duplicate combinations.



class Solution {
private:
    vector<int> candidates;
    set<vector<int>> res_tmp;   // 使用 set 暂存结果，使组合不重复
    vector<int> path;

public:
    // 方法1 ： 回溯法
    // 使用 path 暂存当前递归的中已选择的候选数，每选一个就用 target 减去当前的数
    // 当 target 为 0 时，当前 path 满足要求，存入结果数组
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 先将候选数组排序，以实现剪枝
        this->candidates = candidates;
        DFS(0, target);
        vector<vector<int>> res;
        set<vector<int>>::iterator iter;
        for(iter = res_tmp.begin(); iter != res_tmp.end(); ++iter){ // 将 set 中的组合取出，放入结果数组中
            res.push_back(*iter);
        }
        return res;

    }
    void DFS(int start, int target) {
        int len = candidates.size();
        if (target == 0) {
            res_tmp.insert(path);
            return ;
        }
        for (int i = start; i < len && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);      // 选择当前 candidates[i]
            DFS(i + 1, target - candidates[i]); // 当前数不能重复选，所以是 i + 1
            path.pop_back();                    // 恢复上一状态
        }
    }

};
int main(){
    Solution s;

    return 0;
}
