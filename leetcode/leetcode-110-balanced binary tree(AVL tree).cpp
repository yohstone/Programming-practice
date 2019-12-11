#include<iostream>
#include<algorithm>
using namespace std;

    // 给定一个二叉树，判断它是否是高度平衡的二叉树。

    // 本题中，一棵高度平衡二叉树定义为：

    // 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

    // 示例 1:

    // 给定二叉树 [3,9,20,null,null,15,7]

    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // 返回 true 。

    // 示例 2:

    // 给定二叉树 [1,2,2,3,3,null,null,4,4]

    //        1
    //       / \
    //      2   2
    //     / \
    //    3   3
    //   / \
    //  4   4
    // 返回 false 。

    // Given a binary tree, determine if it is height-balanced.
    // For this problem, a height-balanced binary tree is defined as:
    // a binary tree in which the left and right subtrees of every node differ in height by no more than 1.




// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：从底至顶，做深度优先遍历，遇到左右子树高度相差大于1时，直接返回 -1 结束递归
    // 时间复杂度 O(n)，最坏的情况是对树做一次完整的 DFS
    bool isBalanced(TreeNode* root) {
        return DFS(root) != -1;
    }

    // 深度优先遍历
    int DFS(TreeNode* root){
        if(root == nullptr){ // 叶子节点返回0
            return 0;
        }
        int left_depth = DFS(root->left);
        if(left_depth == -1){
            return -1;
        }
        int right_depth = DFS(root->right);
        if(right_depth == -1){
            return -1;
        }
        if(abs(left_depth - right_depth) > 1){  // 左右子树高度相差大于1，则返回 -1
            return -1;
        }
        return  max(left_depth, right_depth) + 1; 
    }

    // 方法2：暴力法，从顶至底，做深度优先遍历，递归判断每一个节点的左右子树高度是否相差大于1
    // 时间复杂度 O(n^2)，会重复访问节点
    bool isBalanced2(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return abs(DFS2(root->left) - DFS2(root->right)) < 2 // 判断当前根的左右子树是否失衡
                && isBalanced2(root->left)                   // 以左子树为根判断是否失衡
                && isBalanced2(root->right);                 // 以右子树为根判断是否失衡
    }

    // 深度优先遍历，计算每个节点的高度
    int DFS2(TreeNode* root){
        if(root == nullptr){ // 叶子节点返回0
            return 0;
        }
        return max(DFS2(root->left), DFS2(root->right)) + 1; // 递归计算高度
    }

};


int main(){

	return 0;
}
