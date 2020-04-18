#include<iostream>
#include<set>
using namespace std;

// 73. 矩阵清零

// 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

// 示例 1:

//     输入: 
//     [
//       [1,1,1],
//       [1,0,1],
//       [1,1,1]
//     ]
//     输出: 
//     [
//       [1,0,1],
//       [0,0,0],
//       [1,0,1]
//     ]
//     示例 2:

//     输入: 
//     [
//       [0,1,2,0],
//       [3,4,5,2],
//       [1,3,1,5]
//     ]
//     输出: 
//     [
//       [0,0,0,0],
//       [0,4,5,0],
//       [0,3,1,0]
//     ]

// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.



class Solution {
public:
    // 方法1：使用额外存储空间，首先第一遍遍历使用两个 set 分别把要清零的行和列记下，
    //       然后第二遍遍历负责清零
    // 时间复杂度 O(n*m)  空间复杂度 O(m+n)
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows; // 行标记
        set<int> cols; // 列标记
        int row_size = matrix.size();
        int col_size = matrix[0].size();


        // 记录要清零的行和列
        for(int i = 0; i  < row_size; ++i){
            for(int j = 0; j < col_size; ++j){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // 清零
        for(int i = 0; i < row_size; ++i){
            for(int j = 0; j < col_size; ++j){
                if(rows.find(i) != rows.end() || cols.find(j) != cols.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // 方法2：不使用额外存储空间，当 matrix[i][j] 为 0 时，将列头 matrix[0][j] 和行头 matrix[i][0] 设为 0 作为标记；
    //       然后第二次遍历时根据列头和行头是否为零来进行清零。
    // 时间复杂度 O(n*m)  空间复杂度 O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_col_flag = false;  // 第一列的标记，因为第一行和第一列都是使用matrix[0][0]，所以需单独再设置一个变量作为标记
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        if(matrix[0][0] == 0){
            first_col_flag = true;
        }
        // 记录要清零的行和列
        for(int i = 0; i  < row_size; ++i){
            for(int j = 0; j < col_size; ++j){
                if(i != 0 && j == 0 && matrix[i][0] == 0){ // 第一列有 0 的情况
                    first_col_flag = true;
                    continue;
                }
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // 倒着清零
        for(int i = row_size - 1; i >= 0; --i){
            for(int j = col_size - 1; j >= 0; --j){
                if(j == 0 && first_col_flag == true){     // 第一列清零
                    matrix[i][j] = 0;
                    continue;
                }
                if(j != 0 && (matrix[0][j] == 0 || matrix[i][0] == 0) ){ // 把第一列剔除
                    matrix[i][j] = 0;
                }
            }
        }
    }

};
int main() {
    Solution s;

    return 0;
}
