#include<iostream>
using namespace std;

	// 旋转图像

	// 给定一个 n × n 的二维矩阵表示一个图像。

	// 将图像顺时针旋转 90 度。

	// 说明：

	// 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

	// 示例 1:

	// 给定 matrix = 
	// [
	//   [1,2,3],
	//   [4,5,6],
	//   [7,8,9]
	// ],

	// 原地旋转输入矩阵，使其变为:
	// [
	//   [7,4,1],
	//   [8,5,2],
	//   [9,6,3]
	// ]

	// You are given an n x n 2D matrix representing an image.

	// Rotate the image by 90 degrees (clockwise).

	// Note:

	// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
	// DO NOT allocate another 2D matrix and do the rotation.




class Solution {
public:
	// 方法1：先转置再翻转
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size(); // 方阵的长度

        // 转置(沿着对角线翻转)
        for(int i = 0; i < len; ++i){
        	for(int j = i; j < len; ++j){
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[j][i];
        		matrix[j][i] = temp;
        	}
        }

        // 翻转（沿着竖直线翻转）
        for(int i = 0; i < len; ++i){
        	for(int j = 0; j < len / 2; ++j){
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[i][len - j - 1];
        		matrix[i][len - j - 1] = temp;
        	}
        }
    }
};




int main(){

    return 0;
}
