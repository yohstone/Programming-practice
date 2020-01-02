#include<iostream>
#include<vector>
using namespace std;

//    给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
//
//    示例 1:
//
//    输入:
//    [
//     [ 1, 2, 3 ],
//     [ 4, 5, 6 ],
//     [ 7, 8, 9 ]
//    ]
//    输出: [1,2,3,6,9,8,7,4,5]
//    示例 2:
//
//    输入:
//    [
//      [1, 2, 3, 4],
//      [5, 6, 7, 8],
//      [9,10,11,12]
//    ]
//    输出: [1,2,3,4,8,12,11,10,9,5,6,7]
//
//    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.



class Solution {
public:
    // 方法1：每一圈左上角的坐标中，行号与列号都是相同的，以左上角的点 (start, start) 作为分析条件
    // 经过分析发现，到最后一圈时，columns > start * 2 && rows > start * 2 依然成立，所以以此为循环条件
    // 时间复杂度 O(n * m)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }
        int rows = matrix.size();       // 行数
        int columns = matrix[0].size(); // 列数

        int start = 0;
        while(columns > start * 2 && rows > start * 2){
            traverseMatrixInCircle(matrix, res, columns, rows, start);
            ++start;
        }
        return res;
    }
    // 按顺时针方向遍历矩阵的一圈
    void traverseMatrixInCircle(vector<vector<int>> &matrix, vector<int> &res, int columns, int rows, int start){
        int end_x = columns - 1 - start;    // 当前圈的结束列号
        int end_y = rows - 1 - start;       // 当前圈的结束行号
        for(int i = start; i <= end_x; ++i){        // 1. 从左到右遍历一行
            res.push_back(matrix[start][i]);
        }
        if(start < end_y){                          // 起始行号需要小于结束行号
            for(int i = start + 1; i <= end_y; ++i){// 2. 从上到下遍历一列
                res.push_back(matrix[i][end_x]);
            }
        }
        if(start < end_y && start < end_x){         // 起始行号与列号都需要小于结束行号与列号
            for(int i = end_x - 1; i >= start; --i){// 3. 从右到左遍历一行
                res.push_back(matrix[end_y][i]);
            }
        }
        if(start < end_x && start < end_y - 1){     // start 需 <= end_y - 2
            for(int i = end_y - 1; i >= start + 1; --i){    // 4. 从下到上遍历一列
                res.push_back(matrix[i][start]);
            }
        }
    }


    // 方法2：用变量表示上下左右的边界，然后每遍历完一行或一列，更新边界值，当两边界交错，则结束
    // 1. 设定上下左右边界
    // 2. 先从左向右遍历第一行，此时第一行因为已经使用过了，可以将其从矩阵中删去，体现在代码中就是重新定义上边界
    // 3. 若上下边界不交错，则遍历还未结束，接着分别向下、向左、向上遍历，操作过程与2，3步同理
    // 4. 不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }
        int upper_boundary = 0;                     // 上边界
        int lower_boundary = matrix.size() - 1;     // 下边界，即 行数 - 1
        int right_boundary = matrix[0].size() - 1;  // 右边界，即 列数 - 1
        int left_boundary  = 0;                     // 左边界
        while(true){
            for(int i = left_boundary; i <= right_boundary; ++i){   // 1. 从左到右遍历最上一行
                res.push_back(matrix[upper_boundary][i]);
            }
            if(++upper_boundary > lower_boundary)   break;          // 重新设定上边界，若上边界大于下边界，则遍历完成

            for(int i = upper_boundary; i <= lower_boundary; ++i){  // 2. 从上到下遍历最右一列
                res.push_back(matrix[i][right_boundary]);
            }
            if(--right_boundary < left_boundary)    break;          // 重新设定右边界，若右边界大于左边界，则遍历完成

            for(int i = right_boundary; i >= left_boundary; --i){   // 3. 从右到左遍历最下一行
                res.push_back(matrix[lower_boundary][i]);
            }
            if(--lower_boundary < upper_boundary)   break;          // 重新设定下边界

            for(int i = lower_boundary; i >= upper_boundary; --i){  // 4. 从下到上遍历最左一列
                res.push_back(matrix[i][left_boundary]);
            }
            if(++left_boundary > right_boundary)    break;          // 重新设定左边界
        }
        return res;
    }
};
int main() {
    Solution s;
    return 0;

}
