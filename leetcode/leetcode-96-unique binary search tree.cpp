#include<iostream>
#include<vector>
using namespace std;

//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//
//示例:
//
//输入: 3
//输出: 5
//解释:
//给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3



class Solution {
public:
    // 方法1：动态规划法，
    // G(n) 表示以 1 ... n 为节点组成的二叉搜索树的种类数量
    // F(i, n) 表示以 1 ... n 为节点组成的二叉搜索树中，以 i 为结点的二叉搜索树数量
    // 则 G(n) = ∑F(i, n)  ，i 为 1 ~ n
    // 又 F(i, n) = G(i-1) * G(n-i)
    // 所以 G(n) = ∑G(i-1) * G(n-i)  ，i 为 1 ~ n
    int numTrees(int n) {
        vector<int> G(n+1, 0);
        G[0] = 1;
        G[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                G[i] += G[j-1] * G[i-j];
            }
        }
        return G[n];

    }
};


int main(){

	return 0;
}
