#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//
//输入:
//
//   1
// /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
//
//Given a binary tree, return all root-to-leaf paths.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Input:
//
//   1
// /   \
//2     3
// \
//  5
//
//Output: ["1->2->5", "1->3"]
//
//Explanation: All root-to-leaf paths are: 1->2->5, 1->3



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：递归法，
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr) return res;
        string currPath;
        binaryTreePaths(root, res, currPath);
        return res;
    }
    // 方法1 的递归核心函数，注意 curPath 不用引用，这样每个函数中的 curPath 都不一样
    void binaryTreePaths(TreeNode* root, vector<string> &res, string curPath){
        if(root == nullptr) return;
        curPath += to_string(root->val);
        curPath += "->";
        if(root->left == nullptr && root->right == nullptr){
            curPath.erase(curPath.size() - 2);
            res.push_back(curPath);
        }
        binaryTreePaths(root->left, res, curPath);
        binaryTreePaths(root->right, res, curPath);
    }
};
int main(){

	return 0;
}
