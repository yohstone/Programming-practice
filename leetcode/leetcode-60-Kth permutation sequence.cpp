#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//    给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
//
//    按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//
//    "123"
//    "132"
//    "213"
//    "231"
//    "312"
//    "321"
//    给定 n 和 k，返回第 k 个排列。
//
//    说明：
//
//    给定 n 的范围是 [1, 9]。
//    给定 k 的范围是[1,  n!]。
//    示例 1:
//
//    输入: n = 3, k = 3
//    输出: "213"
//    示例 2:
//
//    输入: n = 4, k = 9
//    输出: "2314"
//
//    The set [1,2,3,...,n] contains a total of n! unique permutations.
//
//    By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
//    "123"
//    "132"
//    "213"
//    "231"
//    "312"
//    "321"
//    Given n and k, return the kth permutation sequence.
//
//    Note:
//
//    Given n will be between 1 and 9 inclusive.
//    Given k will be between 1 and n! inclusive.



class Solution {
public:
    // 方法1：使用回溯法的思路思考，则每当选择一个数加入排列时，可以计算出剩下的数还有多少种排列的可能，
    // 即可以计算出当前被选择的数的排列总数，设用 remain_fac 表示， remain_fac = 剩下的待选择的数的阶乘。
    // 然后将 remain_fac 与 k 进行大小比较，若小于 k ，则说明所要求的第 k 个排列不在以 当前选定的数 为开头的所有排列中，直接跳过
    // 一次递归到底就能找到 第 k 个排列
    string getPermutation(int n, int k) {
        vector<bool> isUsed(n + 1, false);          // 用于标记每个数是否用过
        string res = "";                            // 用于返回的结果排列序列

        dfs(isUsed, res, n, k);
        return res;
    }
    // 递归实现
    void dfs(vector<bool> &isUsed, string &res, int n, int k){
        int res_len = res.size();
        if(res_len == n){    // 结束条件，当前排列已经结束
            return;
        }
        int remain_fac = factorial(n - res_len - 1);  // 剩下的数的全排列的个数
        for(int i = 1; i <= n; ++i){                  // 遍历 [1, n]
            if(isUsed[i]){                            // 跳过已使用的数
                continue;
            }
            if(remain_fac > 0 && remain_fac < k){     // 剩下的数的全排列个数小于当前 k ，说明第 k 个排列肯定不在当前的递归子树中，直接跳过该递归
                k -= remain_fac;                      // 剪枝
                continue;
            }
            res = res + static_cast<char>('0' + i);
            isUsed[i] = true;
            dfs(isUsed, res, n, k);
                                                      // 因为是一次递归直接到叶子，所以不需要还原状态
        }
    }
    // 求 n 的阶乘 或者直接使用数组：factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
    int factorial(int n){
        int res = 1;
        while(n > 0){
            res *= n;
            n--;
        }
        return res;
    }

    // 方法2：迭代实现
    string getPermutation2(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; ++i){                // 生成包含 [1, n] 的数组
            nums.push_back(i);
        }
        string res = "";                            // 用于返回的结果排列序列

        int interval = 0;                           // 用于识别应该跳过几个数
        int remain_add_len = n;                     // 待添加的数字个数
        for(int i = 0; i < n; ++i){
            int cur_factorial = factorial(remain_add_len - 1);      // 剩下待加长度中每个数都有多少种排列数
            interval = (k - 1) / cur_factorial;                 // 到第 k 个排列间隔几个数
            res = res + static_cast<char>('0' + nums[interval]);    // 加上去掉间隔中的数后的第一个数
            nums.erase(nums.begin() + interval);                    // 数组中删掉被加入的数
            remain_add_len--;
            k = k - interval * cur_factorial;
        }
        return res;
    }



    // 方法3：暴力法，先求出 n 个数的全排列，当求到第 k 个时，返回。超时
    vector<vector<int>> permutation;
    string getPermutation3(int n, int k) {
        vector<int> track;                      // 用于暂存每种排列
        vector<int> nums;
        for(int i = 1; i <= n; ++i){            // 根据 n 生成 nums 数组
            nums.push_back(i);
        }
        backtrack(nums, track, k);

        string res = "";
        for(int num : permutation[k - 1]){     // 将第 k 个排列拼成字符串序列
            res = res + static_cast<char>('0' + num);
        }
        return res;
    }

    // 回溯法求全排列
    void backtrack(vector<int> &nums, vector<int> &track, int k){
        if(track.size() == nums.size()){    // 结束条件，一种排列已经结束
            permutation.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(find(track.begin(), track.end(), nums[i]) != track.end()){   // 排除不合法的选择，跳过已使用的数
                // 也可以使用 isUsed 数组记录已使用过的数，以空间换时间
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track, k);
            if(permutation.size() == k){    // 如果已经生成第 k 个，结束
                return;
            }
            track.pop_back();
        }
    }
};


int main(){
    return 0;
}
