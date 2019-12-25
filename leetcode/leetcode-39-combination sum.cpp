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
    // 使用 path 暂存当前递归的中已选择的候选数，每选一个就用 target 减去当前的数
    // 当 target 为 0 时，当前 path 满足要求，存入结果数组
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 先将候选数组排序，以实现剪枝
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

    // 方法2 ： 动态规划
    // dict[i, []] ： 目标值为 i 时，对应的组合方式种类
    // dict[i, []] = dict[i - num, [] ] 中每种组合方式加上 num
    vector<vector<int>> combinationSum2(vector<int> & candidates, int target){
        unordered_map<int, set<vector<int>> > dict;
        for(int i = 1; i <= target; ++i){               // 从 1 遍历到 target，求每个数的组合方式
            for(int num : candidates){                  // 遍历候选数数组，确定组合中可以包含的数
                if(i == num){
                    dict[i].insert(vector<int> {num});  // 候选数组中有目标值时，目标值自身可作为一种组合方式
                }
                else if(i > num){
                    for(auto vec : dict[i - num]){      // 遍历目标数为 i - num 时的所有组合方式
                        vec.push_back(num);
                        sort(vec.begin(), vec.end());   // 排序后能达到去重的效果，保证了每个 vector 在 set 中是唯一的
                        if(dict[i].count(vec) == 0){    // 若 set 中没有当前加入了 num 的 vector，则将 vector 插入
                            dict[i].insert(vec);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(auto vec : dict[target]){                   // 将目标值的组合方式数组转换成需返回的 vector
            res.push_back(vec);
        }
        return res;
    }
};
int main(){
    Solution s;

    return 0;
}
