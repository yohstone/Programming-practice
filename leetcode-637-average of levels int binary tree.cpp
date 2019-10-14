#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
//
//示例 1:
//
//输入:
//    3
//   / \
//  9  20
//    /  \
//   15   7
//输出: [3, 14.5, 11]
//解释:
//第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
//注意：
//
//节点值的范围在32位有符号整数范围内。
//
//Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.





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
    // 使用 toBeAddedNodes 来记录当前层剩余需要遍历的结点数量， 使用 nextLevelNodesAmount 来记录下一层的结点数
    // 同时计算每层的结点值的和以及平均值
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode *> treeNodesQueue;
        int nextLevelNodesAmount = 0;   // 下一层结点数量
        int toBeAddedNodes = 1;         // 待添加的结点数量
        long long curLevelSum = 0;      // 当前节点值的和
        int curLevelNodesAmount = 1;    // 当前层结点数量

        treeNodesQueue.push(root);
        while(!treeNodesQueue.empty()){

            TreeNode* pNode = treeNodesQueue.front();
            curLevelSum = curLevelSum + pNode->val;

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
            if(toBeAddedNodes == 0){          // 当前层的树结点已全部遍历完

                double average = static_cast<double>(curLevelSum) / static_cast<double>(curLevelNodesAmount);
                res.push_back(average);
                toBeAddedNodes = nextLevelNodesAmount;
                curLevelNodesAmount = nextLevelNodesAmount;
                curLevelSum = 0;
                nextLevelNodesAmount = 0;
            }
        }
        return res;
    }

    // 方法2：递归法，使用一个 vector 存储结果，两个 辅助 vector 存储每层的结点数量以及每层节点值的和
    vector<double> averageOfLevels2(TreeNode* root) {
        vector<double> levelAverages;
        if(root == nullptr){
            return levelAverages;
        }
        vector<int> levelNodesAmount;
        vector<long long> levelNodesSum;
        averageOfLevels2(root, 0, levelNodesAmount, levelNodesSum);
        for(int i = 0; i < levelNodesAmount.size(); ++i){
            double average = static_cast<double>(levelNodesSum[i]) / static_cast<double>(levelNodesAmount[i]);
            levelAverages.push_back(average);
        }
        return levelAverages;
    }
    void averageOfLevels2(TreeNode* root, int level, vector<int> &levelNodesAmount, vector<long long> &levelNodesSum) {
        if(root == nullptr)
            return;
        if(levelNodesAmount.size() == level){  // 开始遍历新的一层
            levelNodesAmount.push_back(0);
            levelNodesSum.push_back(0);
        }
        ++levelNodesAmount[level];
        levelNodesSum[level] = levelNodesSum[level] + root->val;
        averageOfLevels2(root->left, level + 1, levelNodesAmount, levelNodesSum);
        averageOfLevels2(root->right, level + 1, levelNodesAmount, levelNodesSum);
    }
};

int main(){

	return 0;
}
