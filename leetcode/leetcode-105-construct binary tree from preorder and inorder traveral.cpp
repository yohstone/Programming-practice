#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//根据一棵树的前序遍历与中序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]
//返回如下的二叉树：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() <= 0 || inorder.size() <= 0){
            return nullptr;
        }
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        return buildTreeCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTreeCore(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndexInInorder = inorderMap[rootValue];
        int leftLength = rootIndexInInorder - inStart;
        root->left = buildTreeCore(preorder, preStart + 1, preStart + leftLength, inorder, inStart, rootIndexInInorder - 1 );
        root->right = buildTreeCore(preorder, preStart + leftLength + 1, preEnd, inorder, rootIndexInInorder + 1, inEnd );
        return root;
    }
};


int main(){
    Solution s;

    return 0;
}
