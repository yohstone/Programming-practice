#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//给定如下二叉树，以及目标和 sum = 22，
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//返回:
//
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]
//
//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Given the below binary tree and sum = 22,
//
//      5
//     / \
//    4   8
//   /   / \
//  11  13  4
// /  \    / \
//7    2  5   1
//Return:
//
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：递归法，新 sum 等于 sum 减去当前节点的值，然后递归判断其左右子节点，直到叶子节点
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        vector<int> currPath;
        pathSumCore(root, sum, res, currPath);

        return res;
    }
    // 方法1 的递归函数
    void pathSumCore(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &currPath){
        sum = sum - root->val;
        currPath.push_back(root->val);
        if(sum == 0 && root->left == nullptr && root->right == nullptr ){
            res.push_back(currPath);
            return;
        }
        if(root->left){
            pathSumCore(root->left, sum, res, currPath);
            currPath.pop_back(); // 回溯，在返回父结点之前得把当前结点从路径中删除
        }
        if(root->right){
            pathSumCore(root->right, sum, res, currPath);
            currPath.pop_back(); // 回溯，在返回父结点之前得把当前结点从路径中删除
        }
    }

};
int main(){

	return 0;
}
