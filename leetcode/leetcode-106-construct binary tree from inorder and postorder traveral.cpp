#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//根据一棵树的中序遍历与后序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3]
//返回如下的二叉树：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9,3,15,20,7]
//postorder = [9,15,7,20,3]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7



// Definition for a binary tree node
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1，递归实现，先使用一个 map 存储 各节点在中序遍历中的位置，防止每次都需要寻找根结点
    unordered_map<int, int> inorderMap;   // 用于记录中序序列中各结点的位置
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() <= 0 || postorder.size() <= 0){
            return nullptr;
        }
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        return buildTreeCore(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTreeCore(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd){
        if(postStart > postEnd || inStart > inEnd){
            return nullptr;
        }
        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndexInInorder = inorderMap[rootValue];
        int leftLength = rootIndexInInorder - inStart;
        root->left = buildTreeCore(inorder, inStart, rootIndexInInorder - 1, postorder, postStart, postStart + leftLength - 1);
        root->right = buildTreeCore(inorder, rootIndexInInorder + 1, inEnd, postorder, postStart + leftLength, postEnd - 1 );
        return root;
    }
};


int main(){
    Solution s;

    return 0;
}
