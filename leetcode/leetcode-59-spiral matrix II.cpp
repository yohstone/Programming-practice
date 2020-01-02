#include<iostream>
#include<vector>
using namespace std;

//    给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
//
//    示例:
//
//    输入: 3
//    输出:
//    [
//     [ 1, 2, 3 ],
//     [ 8, 9, 4 ],
//     [ 7, 6, 5 ]
//    ]
//
//    Given a positive integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.


class Solution {
public:
    // 方法1：每一圈左上角的坐标中，行号与列号都是相同的，以左上角的点 (start, start) 作为分析条件
    // 经过分析发现，到最后一圈时，columns > start * 2 && rows > start * 2 依然成立，所以以此为循环条件
    // 时间复杂度 O(n * n)
    vector<vector<int>> generateMatrix(int n)  {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        if(n <= 0){
            return matrix;
        }

        int rows = n;    // 行数
        int columns = n; // 列数

        int start = 0;
        int num = 1;     // 待放入矩阵的数
        int end_num = n * n;
        while(num <= end_num){
            traverseMatrixInCircle(matrix, columns, rows, start, num);
            ++start;
        }
        return matrix;
    }
    // 按顺时针方向遍历矩阵的一圈
    void traverseMatrixInCircle(vector<vector<int>> &matrix, int columns, int rows, int start, int &num){
        int end_x = columns - 1 - start;    // 当前圈的结束列号
        int end_y = rows - 1 - start;       // 当前圈的结束行号
        for(int i = start; i <= end_x; ++i){        // 1. 从左到右遍历一行
            matrix[start][i] = num++;
        }
        if(start < end_y){                          // 起始行号需要小于结束行号
            for(int i = start + 1; i <= end_y; ++i){// 2. 从上到下遍历一列
                matrix[i][end_x] = num++;
            }
        }
        if(start < end_y && start < end_x){         // 起始行号与列号都需要小于结束行号与列号
            for(int i = end_x - 1; i >= start; --i){// 3. 从右到左遍历一行
                matrix[end_y][i] = num++;
            }
        }
        if(start < end_x && start < end_y - 1){     // start 需 <= end_y - 2
            for(int i = end_y - 1; i >= start + 1; --i){    // 4. 从下到上遍历一列
                matrix[i][start] = num++;
            }
        }
    }


    // 方法2：用变量表示上下左右的边界，然后每遍历完一行或一列，更新边界值，当两边界交错，则结束
    // 1. 设定上下左右边界
    // 2. 先从左向右遍历第一行，此时第一行因为已经使用过了，可以将其从矩阵中删去，体现在代码中就是重新定义上边界
    // 3. 若 num < n * n，则遍历还未结束，接着分别向下、向左、向上遍历，操作过程与2，3步同理
    // 4. 不断循环以上步骤，直到生成的数 num > n * n，跳出循环，返回答案
    vector<vector<int>> generateMatrix(int n)  {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        if(n <= 0){
            return matrix;
        }
        int upper_boundary = 0;                     // 上边界
        int lower_boundary = n - 1;                 // 下边界，即 行数 - 1
        int right_boundary = n - 1;                 // 右边界，即 列数 - 1
        int left_boundary  = 0;                     // 左边界
        int num = 1;                                // 待添加到矩阵的数
        int end_num = n * n;
        while(num <= end_num){
            for(int i = left_boundary; i <= right_boundary; ++i){   // 1. 从左到右遍历最上一行
                matrix[upper_boundary][i] = num++;
            }
            ++upper_boundary;                                       // 重新设定上边界

            for(int i = upper_boundary; i <= lower_boundary; ++i){  // 2. 从上到下遍历最右一列
                matrix[i][right_boundary] = num++;
            }
            --right_boundary;                                       // 重新设定右边界

            for(int i = right_boundary; i >= left_boundary; --i){   // 3. 从右到左遍历最下一行
                matrix[lower_boundary][i] = num++;
            }
            --lower_boundary;                                       // 重新设定下边界

            for(int i = lower_boundary; i >= upper_boundary; --i){  // 4. 从下到上遍历最左一列
                matrix[i][left_boundary] = num++;
            }
            ++left_boundary;                                        // 重新设定左边界
        }
        return matrix;
    }
};
int main() {
    Solution s;
    return 0;

}
