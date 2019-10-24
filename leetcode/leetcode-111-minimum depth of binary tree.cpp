#include<iostream>
#include<stack>
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
    // 方法1：递归法，深度优先遍历DFS
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

    // 方法2：迭代+深度优先遍历DFS
    int minDepth2(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        stack<pair<TreeNode*, int>> treeStack; // 存储树的结点及其对应的深度
        treeStack.push(make_pair(root, 1));
        int min_depth = INT_MAX;
        while(!treeStack.empty()){
            TreeNode* currNode = treeStack.top().first;
            int currDepth = treeStack.top().second;
            treeStack.pop();
            if(currNode->left == nullptr && currNode->right == nullptr){ // 遇到叶子结点，更新最小深度
                min_depth = min(min_depth, currDepth);
            }
            if(currNode->left){
                treeStack.push(make_pair(currNode->left, currDepth + 1));
            }
            if(currNode->right){
                treeStack.push(make_pair(currNode->right, currDepth + 1));
            }
        }
        return min_depth;
    }
    // 方法3：递归+广度优先遍历 BFS，遇到叶子结点返回，遇到非叶子结点则递归，每递归一次 depth + 1
    int minDepth3(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int depth = 1;
        if(!root->left && !root->right){
            return depth;
        }
        if(!root->left){
            return depth + minDepth3(root->right);
        }
        if(!root->right){
            return depth + minDepth3(root->left);
        }
        return depth + min(minDepth3(root->left), minDepth3(root->right));
    }

    // 方法4：迭代+广度优先遍历，将每一层结点压入队列中，若遇到叶子结点，则说明找到了最小的深度，直接返回层数
    int minDepth4(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        queue<pair<TreeNode*, int>> treeQue; // 存储树的结点及其对应的深度
        treeQue.push(make_pair(root, 1));
        while(!treeQue.empty()){
            TreeNode* currNode = treeQue.front().first;
            int currDepth = treeQue.front().second;
            treeQue.pop();
            if(currNode->left == nullptr && currNode->right == nullptr){ // 遇到叶子结点，更新最小深度
                return currDepth;
            }
            if(currNode->left){
                treeQue.push(make_pair(currNode->left, currDepth + 1));
            }
            if(currNode->right){
                treeQue.push(make_pair(currNode->right, currDepth + 1));
            }
        }
        return 1;
    }

};
int main(){

	return 0;
}
