#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
//
//例如:
//给定二叉树: [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回其层次遍历结果：
//
//[
//  [3],
//  [9,20],
//  [15,7]
//]
//
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).




// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 迭代法， 每一层结点插入一个队列尾部，从队列首部进行遍历
    // 使用 toBeAddedNodes 来记录当前层剩余需要遍历的结点， 使用 nextLevelNodesAmount 来记录下一层的结点数
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode *> treeNodesQueue;
        int nextLevelNodesAmount = 0;   // 下一层结点数量
        int toBeAddedNodes = 1;         // 待添加的结点数量
        vector<int> curLevelNodes;
        treeNodesQueue.push(root);
        while(!treeNodesQueue.empty()){

            TreeNode* pNode = treeNodesQueue.front();
            curLevelNodes.push_back(pNode->val);
            //cout << pNode->val << ' ';
            if(pNode->left != nullptr){
                treeNodesQueue.push(pNode->left);
                ++nextLevelNodesAmount;
            }
            if(pNode->right != nullptr){
                treeNodesQueue.push(pNode->right);
                ++nextLevelNodesAmount;
            }

            treeNodesQueue.pop();
            --toBeAddedNodes;
            if(toBeAddedNodes == 0){          // 当前层的树结点已全部添加到 vector 里
                //cout << endl;
                res.push_back(curLevelNodes); // 将当前 vector 添加到结果 vector 里
                curLevelNodes.clear();
                toBeAddedNodes = nextLevelNodesAmount;
                nextLevelNodesAmount = 0;
            }
        }
        return res;
    }

    // 递归法，使用一个全局 vector 存储结果
    vector<vector<int> > levels;
    vector<vector<int>> levelOrder2(TreeNode* root) {
        if(root == nullptr){
            return levels;
        }
        levelOrder(root, 0);
        return levels;
    }
    void levelOrder(TreeNode* root, int level) {
        if(levels.size() == level){
            levels.push_back(vector<int> {});
        }
        levels[level].push_back(root->val);
        if(root->left != nullptr){
            levelOrder(root->left, level + 1);
        }
        if(root->right != nullptr){
            levelOrder(root->right, level + 1);
        }

    }
};

int main(){

	return 0;
}
