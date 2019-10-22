#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//示例:
//
//给定有序数组: [-10,-3,0,5,9],
//
//一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
//
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted array: [-10,-3,0,5,9],
//
//One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：递归实现，因为是平衡二叉搜索树，且给的是排好序的数组，所以根结点必然是数组中间的数（为了平衡），然后二分递归根结点的左右子树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return nullptr;
        }
        return sortedArrayToBST(nums, 0, len - 1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high){
        if(low > high){
            return nullptr;
        }
        int rootIndex = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[rootIndex]);
        root->left = sortedArrayToBST(nums, low, rootIndex - 1);
        root->right = sortedArrayToBST(nums, rootIndex + 1, high);
        return root;
    }
};

int main(){

	return 0;
}
