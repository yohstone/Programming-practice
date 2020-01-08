#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//    两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
//
//    给出两个整数 x 和 y，计算它们之间的汉明距离。
//
//    注意：
//    0 ≤ x, y < 2^31.
//
//    示例:
//
//    输入: x = 1, y = 4
//
//    输出: 2
//
//    解释:
//    1   (0 0 0 1)
//    4   (0 1 0 0)
//           ↑   ↑
//
//    上面的箭头指出了对应二进制位不同的位置。
//
//    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//    Given two integers x and y, calculate the Hamming distance.
//
//    Note:
//    0 ≤ x, y < 2^31.




class Solution {
public:
    // 方法1：先异或得到两个数不同位所形成的数，然后计算该数中 1 的个数
    int hammingDistance(int x, int y) {
        int temp = x ^ y;           // 异或得到 x 与 y 中不同的位形成的数
        int res = 0;                // 统计该数各个位上 1 的总数
        while(temp){
            if( (temp & 1) == 1){   // 判断该数的最后一位是不是 1
                ++res;
            }
            temp >> 1;              // 左移该数
        }
        return res;
    }
};
int main(){

	return 0;
}
