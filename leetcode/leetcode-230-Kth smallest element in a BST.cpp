#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

    // 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

    // 说明：
    // 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

    // 示例 1:

    // 输入: root = [3,1,4,null,2], k = 1
    //    3
    //   / \
    //  1   4
    //   \
    //    2
    // 输出: 1
    // 示例 2:

    // 输入: root = [5,3,6,2,4,null,null,1], k = 3
    //        5
    //       / \
    //      3   6
    //     / \
    //    2   4
    //   /
    //  1
    // 输出: 3


    // Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

    // Note: 
    // You may assume k is always valid, 1 ≤ k ≤ BST's total elements.





// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int count;          // 用于递归计数
    int res = -1;       // 用于存储结果
public:
    // 方法1：使用中序遍历法，使用计数变量 count，当遍历到第 k 个元素就停止。递归实现
    // 时间复杂度 O(k)  空间复杂度 O(1) 若考虑递归的栈则为 O(logn) 
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        inTraverse(root);
        return res;
    }
    // 中序遍历树
    void inTraverse(TreeNode* root){
        if(root == nullptr) return;
        inTraverse(root->left);
        --count;
        if(count == 0){
            res = root->val;    // 记录下第 k 小的元素
            return;
        }
        inTraverse(root->right);
    }
};
int main(){

	return 0;
}
