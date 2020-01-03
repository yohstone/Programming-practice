#include<iostream>
#include<vector>
using namespace std;

//    格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
//
//    给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
//
//    示例 1:
//
//    输入: 2
//    输出: [0,1,3,2]
//    解释:
//    00 - 0
//    01 - 1
//    11 - 3
//    10 - 2
//
//    对于给定的 n，其格雷编码序列并不唯一。
//    例如，[0,2,3,1] 也是一个有效的格雷编码序列。
//
//    00 - 0
//    10 - 2
//    11 - 3
//    01 - 1
//    示例 2:
//
//    输入: 0
//    输出: [0]
//    解释: 我们定义格雷编码序列必须以 0 开头。
//         给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
//         因此，当 n = 0 时，其格雷编码序列为 [0]。
//
//    The gray code is a binary numeral system where two successive values differ in only one bit.
//
//    Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.


class Solution {
public:
    // 方法1：动态规划法，
//    设 n 阶格雷码集合为 G(n)，则 n+1 阶格雷码集合 G(n+1) 为：
//    1. 给 n 阶格雷码每个元素二进制形式前面添加 0，得到 G'(n)；
//    2. 设 G(n) 集合倒序（镜像）集合为 R(n)，给 R(n) 每个元素二进制形式前面添加 1，得到 R'(n)；
//    3. G(n+1) = G'(n) ∪ R'(n) 合并两个集合即可得到下一阶格雷码。
//    注：- 因为二进制前加 0 还是原来的数，所以 G(n) = G'(n)；
//        - 使用镜像集合是因为：倒过来并在前面加上 1 后，相邻序列之间的差异就只有一位，才符合要求。
    vector<int> grayCode(int n) {
        vector<int> gray(1, 0); // n = 0 时，格雷码为 0
        for(int i = 0; i < n; ++i){
            int addend = 1 << i;   // 待加的数，用于给上一个格雷编码集合的倒序集合中的每个序列前面 + 1
            for(int j = gray.size() - 1; j >= 0; --j){
                gray.push_back(gray[j] + addend);  // 因为要求的只是长度为 n 的格雷编码，所以只要一直加下去就能得到结果
            }
        }
        return gray;
    }
};
int main(){
    Solution s;
    return 0;
}
