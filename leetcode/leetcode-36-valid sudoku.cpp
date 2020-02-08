#include<iostream>
#include<vector>
using namespace std;

    // 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

    // 数字 1-9 在每一行只能出现一次。
    // 数字 1-9 在每一列只能出现一次。
    // 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

    // 数独部分空格内已填入了数字，空白格用 '.' 表示。

    // 输入:
    // [
    //   ["8","3",".",".","7",".",".",".","."],
    //   ["6",".",".","1","9","5",".",".","."],
    //   [".","9","8",".",".",".",".","6","."],
    //   ["8",".",".",".","6",".",".",".","3"],
    //   ["4",".",".","8",".","3",".",".","1"],
    //   ["7",".",".",".","2",".",".",".","6"],
    //   [".","6",".",".",".",".","2","8","."],
    //   [".",".",".","4","1","9",".",".","5"],
    //   [".",".",".",".","8",".",".","7","9"]
    // ]
    // 输出: false
    // 解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
    //      但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
    // 说明:

    // 一个有效的数独（部分已被填充）不一定是可解的。
    // 只需要根据以上规则，验证已经填入的数字是否有效即可。
    // 给定数独序列只包含数字 1-9 和字符 '.' 。
    // 给定数独永远是 9x9 形式的。


    // Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    // Each row must contain the digits 1-9 without repetition.
    // Each column must contain the digits 1-9 without repetition.
    // Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

    // The Sudoku board could be partially filled, where empty cells are filled with the character '.'.



class Solution {
public:
    // 方法1：使用 3 个哈希表分别统计每一行、每一列、每个 3*3 子宫格中的数字出现的个数
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][10] = {0};      // 用于判断每一行是否有重复数字
        int cols[9][10] = {0};      // 用于判断每一列是否有重复数字
        int boxes[9][10] = {0};     // 用于判断每个 3*3 的子格内是否有重复 的数字
        // vector<unordered_map<int,int>> rows(9), cols(9), boxes(9);
        for(int row = 0; row < 9; ++row){
            for(int col = 0; col < 9; ++col){
                int box_index = (row / 3) * 3 + (col / 3);
                if(board[row][col] != '.'){
                    int cur_num = board[row][col] - '0';
                    ++rows[row][cur_num];        // 当前行的当前数字的出现次数加 1
                    ++cols[col][cur_num];        // 当前列的当前数字的出现次数加 1
                    ++boxes[box_index][cur_num]; // 当前 3*3 子格子里的当前数字的出现次数加 1
                    if(rows[row][cur_num] > 1 || cols[col][cur_num] > 1 
                    || boxes[box_index][cur_num] > 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


int main() {

    return 0;
}
