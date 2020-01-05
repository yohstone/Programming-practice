#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//    给定一个非空二叉树，返回其最大路径和。
//
//    本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
//
//    示例 1:
//
//    输入: [1,2,3]
//
//           1
//          / \
//         2   3
//
//    输出: 6
//    示例 2:
//
//    输入: [-10,9,20,null,null,15,7]
//
//       -10
//       / \
//      9  20
//        /  \
//       15   7
//
//    输出: 42
//
//    Given a non-empty binary tree, find the maximum path sum.
//
//    For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
//    The path must contain at least one node and does not need to go through the root.




// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    int max_path_sum = INT_MIN;
public:
    // 方法1：递归，使用 DFS 遍历树，求每个结点的权值（以该结点为根同时与其中一个子节点相连的最大路径和）
    // 计算每个结点与它另外一个没算在内的子节点的权值之和，与当前全局变量中存储的最大路径和比较，判断是否需要更新最大路径和
    // 时间复杂度 O(n) n 为结点个数，对每个结点访问不超过 2 次
    // 空间复杂度 O(log n) 与树高度相等的递归栈
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return max_path_sum;
    }
    // 求当前结点 root 的最大权值
    int DFS(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left_weight  = max(0, DFS(root->left));         // 判断左子节点的权值是否大于 0
        int right_weight = max(0, DFS(root->right));        // 判断右子节点的权值是否大于 0
        int cur_path_sum = root->val + left_weight + right_weight;      // 当前结点的路径和
        max_path_sum = max(max_path_sum, cur_path_sum);
        return root->val + max(left_weight, right_weight);  // 若子节点的权值大于 0 则加上，否则 + 0，相当于不加
    }
};



int main(){

	return 0;
}
