#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//
//给定二叉树 [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回它的最小深度  2.
//
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Given binary tree [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its minimum depth = 2.



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：递归法
    int minDepth(TreeNode* root){
        if (root == nullptr)
            return 0;
        int leftDepth  = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (root->left == nullptr || root->right == nullptr){ // 只存在左子树或右子树，或都不存在
            return leftDepth + rightDepth + 1;
        }
        return min(leftDepth, rightDepth) + 1;    // 同时存在左右子树
    }
};
int main(){

	return 0;
}
