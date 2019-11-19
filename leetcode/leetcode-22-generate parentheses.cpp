#include<iostream>
#include<vector>
using namespace std;


//    给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
//    例如，给出 n = 3，生成结果为：
//
//    [
//      "((()))",
//      "(()())",
//      "(())()",
//      "()(())",
//      "()()()"
//    ]
//
//    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//    For example, given n = 3, a solution set is:
//
//    [
//      "((()))",
//      "(()())",
//      "(())()",
//      "()(())",
//      "()()()"
//    ]


class Solution {
public:
    // 方法1：回溯法，深度优先遍历 DFS
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {};
        vector<string> res;
        generateParenthesis("", n, n, res);
        return res;
    }
    // cur_str:当前形成的括号组合串， left 剩余可用的左括号数，right 剩余可用的右括号数
    void generateParenthesis(string cur_str, int left, int right, vector<string> &res){
        if(left == 0 && right == 0){ // 没有可以添加的括号了，将结果插入结果数组中
            res.push_back(cur_str);
        }
        if(left > 0){   // 左括号还有剩余，加入
            generateParenthesis(cur_str + '(', left - 1, right, res);
        }
        if(right > 0 && left < right){  // 右括号的剩余大于左括号的剩余时，该组合才会有效
            generateParenthesis(cur_str + ')', left, right - 1, res);
        }
    }

//    方法2：动态规划
//    1. 定义状态 dp[i]：使用 i 对括号能够生成的组合。
//    2. 状态转移方程：
//        i 对括号的一个组合，在 i - 1 对括号的基础上得到；
//        i 对括号的一个组合，一定以左括号 "(" 开始（不一定以 ")" 结尾），为此，我们可以枚举右括号 ")" 的位置，得到所有的组合；
//        枚举的方式就是枚举左括号 "(" 和右括号 ")" 中间可能的合法的括号对数，而剩下的合法的括号对数在与第一个左括号 "(" 配对的右括号 ")" 的后面，这就用到了以前的状态。
//        状态转移方程是：dp[i] = "(" + dp[可能的括号对数] + ")" + dp[剩下的括号对数]
//        “可能的括号对数” 与 “剩下的括号对数” 之和得为 i，故“可能的括号对数” j 可以从 0 开始，最多不能超过 i， 即 i - 1；
//        “剩下的括号对数” + j = i - 1，故 “剩下的括号对数” = i - j - 1。
//        整理得：dp[i] = "(" + dp[j] + ")" + dp[i- j - 1] , j = 0, 1, ..., i - 1
//    3. 思考初始状态和输出：
//        初始状态：因为我们需要 0 对括号这种状态，因此状态数组 dp 从 0 开始，0 个括号当然就是 [""]。
//        输出：dp[n]
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= i - 1; ++j){
                for(auto str1 : dp[j]){
                    for(auto str2 : dp[i - j - 1]){
                        dp[i].push_back('(' + str1 + ')' + str2);
                    }
                }
            }
        }
        return dp[n];
    }

};
int main(){
    Solution s;
    return 0;
}
