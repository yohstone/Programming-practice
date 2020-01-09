#include<iostream>
#include<vector>

using namespace std;

    // 杨辉三角

    // 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

    // 在杨辉三角中，每个数是它左上方和右上方的数的和。

    // 示例:

    // 输入: 5
    // 输出:
    // [
    //      [1],
    //     [1,1],
    //    [1,2,1],
    //   [1,3,3,1],
    //  [1,4,6,4,1]
    // ]


    // Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

    // In Pascal's triangle, each number is the sum of the two numbers directly above it.


class Solution {
public:
    // 方法1：动态规划，每一行除了首尾整数之外的整数，都等于上一行对应的两个整数之和，即：
    // 设 tri[i][j] 表示第 i 行的第 j 个整数，
    // 则 tri[i][j] = tri[i-1][j-1] + tri[i-1][j]
    // 时间复杂度： O(n^2) 空间复杂度 O(n^2)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        res.push_back({1});
        if(numRows == 1) return res;

        for(int i = 1; i < numRows; ++i){   // 从第 2 行开始
            res.push_back({});
            for(int j = 0; j <= i ; ++j){
                if(j == 0 || j == i){       // 插入每一行首尾的 1 
                    res[i].push_back(1);
                }else{
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]); 
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
