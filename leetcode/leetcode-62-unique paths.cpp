#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//
//    一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//    问总共有多少条不同的路径？
//
//    说明：m 和 n 的值均不超过 100。
//
//    示例 1:
//
//    输入: m = 3, n = 2
//    输出: 3
//    解释:
//    从左上角开始，总共有 3 条路径可以到达右下角。
//    1. 向右 -> 向右 -> 向下
//    2. 向右 -> 向下 -> 向右
//    3. 向下 -> 向右 -> 向右
//    示例 2:
//
//    输入: m = 7, n = 3
//    输出: 28
//
//
//
//    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//    How many possible unique paths are there?



class Solution {
public:
    // 方法1：排列组合法，假设先往下走，需走 m - 1 步，然后往右走，需走 n - 1 步，
    // 所以总共需要 (m - 1) + (n - 1) 步
    // 假设只往一个方向走 (m - 1) + (n - 1) 步，若选择向下走，然后我们从总步数中选择 (n - 1)步为向右走，就能到达右下角
    // 同理，若只往右一直走 (m - 1) + (n - 1) 步，若我们选择其中的 (m - 1) 步向下走，就能到达右下角
    // 即 C（（m + n - 2）， （n - 1）） = C（（m + n - 2）， （m- 1））
    // C（（m + n - 2）， （m- 1）） = (m + n - 2)! / ((m - 1)! * ( (m + n - 2) - (m - 1) )!)
    //   = (m + n - 2)(m + n - 3)(m + n - 4)...(m + n - 2 - m - 1 + 1) / (m - 1)!
    // 时间复杂度 O(m)  空间复杂度 O(1)
    int uniquePaths(int m, int n) {
        long double res = 1;
        for(int i = 1; i <= m - 1; ++i){    // 选择 C（（m + n - 2）， （m- 1））
            res = res * (m + n - 1 - i);    // (m + n - 2)(m + n - 3)(m + n - 4)...(m + n - 2 - m - 1 + 1)
            res /= i;                       // (m - 1)!
        }
        return static_cast<int>(res);
    }

    // 方法2：动态规划
    // 设 dp[i][j] 表示：到达 [i, j] 位置的格子共有多少条路径
    // 则 dp[i][j] = dp[i - 1][j] + dp[i][j - 1]  即 左边格子的路径总数 + 上边格子的路径总数
    // 左边界和上边界的格子 dp[0][j] dp[i][0] 都为 1
    // 时间复杂度 O(m * n)  空间复杂度 O(m * n)
    int uniquePaths2(int m, int n) {
        if(m == 0|| n == 0) return 1;
        vector<vector<int>> dp(m, vector<int> (n, 0));      // 设初始值都为 0

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }

            }
        }
        return dp[m - 1][n - 1];
    }
    // 方法2 优化空间复杂度，一行一行的进行计算
    // 1111 1234 13610 这样一行一行的算，cur[j] = cur[j] + cur[j-1]，等号右边分别是该位置上边的值和左边的值
    // 时间复杂度 O(m * n)  空间复杂度 O(n)
    int uniquePaths3(int m, int n) {
        if(m == 0|| n == 0) return 1;
        vector<int> dp(n, 1);      // 设初始值都为 1

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main(){
    return 0;
}
