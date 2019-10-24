#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//
//在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
//
//示例:
//
//输入:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//输出: 4
//
//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//Example:
//
//Input:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Output: 4



class Solution {
public:
    // 方法2：动态规划，dp[i][j] 表示以坐标(i,j)为正方形右下角元素的最大边长
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows + 1, vector<int> (cols + 1, 0));
        int maxLen = 0;
        for(int i = 1; i <= rows; ++i){
            for(int j = 1; j <= cols; ++j){
                if( matrix[i - 1][j - 1] == '1'){
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};


int main(){

	return 0;
}
