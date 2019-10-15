#include<iostream>
using namespace std;

//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
//return its depth = 3.


// Definition for a binary tree node
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 按照前序顺序建立二叉树
void createBiTree(TreeNode* &node){
    int c;
    cin >> c;
    if( c == -1 )     //当遇到-1时，令该节点为NULL，从而结束该分支的递归
        node = NULL;
    else
    {
        node = new TreeNode(c);
        //node->val = c;
        createBiTree( node->left );
        createBiTree( node->right );
    }
}

class Solution{
public:
    int maxDepth(TreeNode* root){
        if( root == NULL ){
            return 0;
        }
        int leftDepth = maxDepth( root->left );
        int rightDepth = maxDepth( root->right );
        return ( leftDepth > rightDepth ? leftDepth : rightDepth ) + 1;
    }
};


int main(){
    Solution s;
    TreeNode *root;
    createBiTree(root);
    cout << "the tree has been created!" << endl;
    cout << s.maxDepth(root) << endl;
    return 0;
}
