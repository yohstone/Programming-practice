#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
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
    // 方法1：迭代法， 每一层结点插入一个队列尾部，从队列首部进行遍历
    // 使用 toBeAddedNodes 来记录当前层剩余需要遍历的结点， 使用 nextLevelNodesAmount 来记录下一层的结点数
    // 将每层的结点 vector 插入 结果 vector， 最后再反转 结果 vector
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
                res.push_back(curLevelNodes); // 将当前 vector 插入到到结果 vector 尾部，最后再翻转整个 vector， 也可以在直接使用 res.insert(res.begin(), curLevelNodes);
                curLevelNodes.clear();
                toBeAddedNodes = nextLevelNodesAmount;
                nextLevelNodesAmount = 0;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // 方法2：递归法，使用一个全局 vector 存储结果
    vector<vector<int> > levels;
    vector<vector<int>> levelOrderBottom2(TreeNode* root) {
        if(root == nullptr){
            return levels;
        }
        levelOrderBottom2(root, 0);
        reverse(levels.begin(), levels.end());
        return levels;
    }
    void levelOrderBottom2(TreeNode* root, int level) {
        if(levels.size() == level){
            levels.push_back(vector<int> {});
        }
        levels[level].push_back(root->val);
        if(root->left != nullptr){
            levelOrderBottom2(root->left, level + 1);
        }
        if(root->right != nullptr){
            levelOrderBottom2(root->right, level + 1);
        }
    }

    // 方法3：旧方法，先将每一层的结点 vector 存入一个栈中，最后再从栈里取出存入结果 vector ，不需要 reverse 函数，效率差不多
    vector<vector<int>> levelOrderBottom3(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        stack<vector<int>> st;          // 暂存每层数据
        queue<TreeNode*> que;           // 暂存树的每一层节点指针，用于遍历树
        que.push(root);
        while(!que.empty()){
            vector<int> vector_temp;    // 存储每层节点的值
            int que_size = que.size();  // 队列que的大小
            for(int i = 0; i < que_size; i++){
                TreeNode* node = que.front();
                vector_temp.push_back(node->val);
                que.pop();
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            st.push(vector_temp);        // 将每层数据压入栈中
        }

        while(!st.empty()){              // 取出栈中的数据，则可得自底向上遍历的结果
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

int main(){

	return 0;
}
