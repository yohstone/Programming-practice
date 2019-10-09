#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//给定一个二叉树，返回它的中序 遍历。
//
//示例:
//
//输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2]

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderTraverseSeq;
        if(root != nullptr){
            inorderTraversal(root, inorderTraverseSeq);
        }
        return inorderTraverseSeq;
    }
    // 方法1 中序遍历递归实现，将遍历的结点值存入容器中
    void inorderTraversal(TreeNode* root, vector<int> &inorderTraverseSeq){
        if(root == nullptr){
            return;
        }
        inorderTraversal(root->left, inorderTraverseSeq);
        inorderTraverseSeq.push_back(root->val);
        inorderTraversal(root->right, inorderTraverseSeq);
    }

    // 方法2：中序遍历迭代实现，将遍历的结点值存入容器中
    void inorderTraversal2(TreeNode* root, vector<int> &inorderTraverseSeq){
        if(root == nullptr){
            return;
        }
        stack<TreeNode *> nodeStack;      // 用于暂存树中的结点
        TreeNode* p = root;
        while(p != nullptr || !nodeStack.empty()){
            if(p != nullptr){
                nodeStack.push(p);
                p = p->left;              // 一直找到最左结点，然后开始遍历
            }else{
                p = nodeStack.top();
                nodeStack.pop();
                inorderTraverseSeq.push_back(p->val);
                p = p->right;
            }
        }
    }
};


int main(){

	return 0;
}
