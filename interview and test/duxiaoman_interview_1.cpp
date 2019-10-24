#include<iostream>
#include<vector>
using namespace std;

//给定一个二叉树，找出其中最大值的深度。
//
//示例：
//给定二叉树 [3,9,20,null,null,15,7]，
//
//  3
// / \
//9   20
//   /  \
//  15   7
//返回 20 的最大深度 2 。





typedef struct treeNode{
    int val;
    treeNode* left;
    treeNode* right;
}treeNode;




int depth = 0;  // 记录最大的数所在节点的深度
int maxVal = 0; // 记录最大的数

// 寻找二叉树中最大的数所在节点的深度
int findMaxDepth(treeNode* root, int preDepth){
    if(root == nullptr) return 0;
    if(root->val > maxVal){
        maxVal = root->val;
        depth = preDepth + 1;
    }
    if(!root->left && !root->right){
        return depth;
    }
    if(root->left){
        return findMaxDepth(root->left, preDepth + 1);
    }
    if(root->right){
        return findMaxDepth(root->right, preDepth + 1);
    }
    return depth;
}

int main(){
    
    return 0;
}
