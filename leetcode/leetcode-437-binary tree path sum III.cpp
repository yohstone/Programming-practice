#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//给定一个二叉树，它的每个结点都存放着一个整数值。
//
//找出路径和等于给定数值的路径总数。
//
//路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
//
//二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
//
//示例：
//
//root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//返回 3。和等于 8 的路径有:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3.  -3 -> 11
//
//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
//The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
//Example:
//
//root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. -3 -> 11




// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：最简单的递归，其中包含了重复计算
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return 0;
        }
        return pathSumCore(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    // 方法1 的递归函数
    int pathSumCore(TreeNode* root, int sum){
        if(root == nullptr){
            return 0;
        }
        sum = sum - root->val;
        return (sum == 0 ? 1 : 0) + pathSumCore(root->left, sum) + pathSumCore(root->right, sum);
    }

    // 方法2：使用vector存储下当前路径下遍历过的结点，每遍历到一个结点，就倒序遍历 vector，求出每个包含当前结点的符合要求的结果
    int pathSum2(TreeNode* root, int sum){
        vector<int> path;
        int pathCount = 0;
        pathSumCore2(root, sum, path, pathCount);
        return pathCount;
    }
    void pathSumCore2(TreeNode* root, int sum, vector<int> &path, int &pathCount){
        if(root == nullptr) return;
        path.push_back(root->val);
        int currSum = 0;
        for(int i = path.size() - 1; i >= 0; i--){
            currSum = currSum + path[i];
            if(currSum == sum){
                pathCount++;
            }
        }
        pathSumCore2(root->left, sum, path, pathCount);
        pathSumCore2(root->right, sum, path, pathCount);
        path.pop_back();
    }

};
int main(){

	return 0;
}
