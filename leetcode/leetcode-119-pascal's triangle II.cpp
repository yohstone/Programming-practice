#include<iostream>
#include<vector>

using namespace std;
    
    // 杨辉三角2

    // 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

    // 在杨辉三角中，每个数是它左上方和右上方的数的和。

    // 示例:

    // 输入: 3
    // 输出: [1,3,3,1]
    // 进阶：

    // 你可以优化你的算法到 O(k) 空间复杂度吗？

    // Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

    // Note that the row index starts from 0.

    // In Pascal's triangle, each number is the sum of the two numbers directly above it.



class Solution {
public:
    // 方法1：动态规划，先求出整个杨辉三角，然后返回第 rowIndex 行
    // 每一行除了首尾整数之外的整数，都等于上一行对应的两个整数之和，即：
    // 设 tri[i][j] 表示第 i 行的第 j 个整数，
    // 则 tri[i][j] = tri[i-1][j-1] + tri[i-1][j]
    // 时间复杂度： O(n^2) 空间复杂度 O(n^2)
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> tri;
        tri.push_back({1});

        for(int i = 1; i <= rowIndex; ++i){   // 从第 2 行开始
            tri.push_back({});
            for(int j = 0; j <= i ; ++j){
                if(j == 0 || j == i){       // 插入每一行首尾的 1 
                    tri[i].push_back(1);
                }else{
                    tri[i].push_back(tri[i - 1][j - 1] + tri[i - 1][j]); 
                }
            }
        }
        return tri[rowIndex];
    }

    // 方法2：动态规划，直接循环求到第 rowIndex 行
    // 每一行除了首尾整数之外的整数，都等于上一行对应的两个整数之和，即：
    // 设 tri[i][j] 表示第 i 行的第 j 个整数，
    // 则 tri[i][j] = tri[i-1][j-1] + tri[i-1][j]
    // 从后往前加，加到第二个数停止
    // 时间复杂度： O(n^2) 空间复杂度 O(k)
    vector<int> getRow2(int rowIndex) {
        vector<int> tri_row(rowIndex + 1, 0);
        tri_row[0] = 1;

        for(int i = 1; i <= rowIndex; ++i){   // 从第 2 行开始
            for(int j = i; j >= 1 ; --j){     // 每一行都是从后往前生成新的一行
                tri_row[j] += tri_row[j - 1];
            }
        }
        return tri_row;
    }
};

int main() {
    Solution s;
    return 0;
}
