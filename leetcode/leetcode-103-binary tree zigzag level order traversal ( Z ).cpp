#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Z 字形遍历、之字形遍历、锯齿形层次遍历
// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回锯齿形层次遍历如下：
//
//[
//  [3],
//  [20,9],
//  [15,7]
//]
//
//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).




// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：迭代法，因为奇偶层数的遍历方向相反，所以使用两个栈分别存储，遍历奇数层的时候将子节点存入偶数层的栈中。
    // 遍历偶数层的时候将子节点存入奇数层的栈中，这样从栈取出遍历的时候方向就相反了。
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }

        stack<TreeNode*> levels[2];  // 两个栈用于存储奇偶层数的结点
        int current = 0;
        int next = 1;
        vector<int> level;

        levels[current].push(root);
        while(!levels[0].empty() || !levels[1].empty() ){
            TreeNode* pNode = levels[current].top();
            levels[current].pop();

            level.push_back(pNode->val);
           // cout << pNode->val << ' ';

            if(current == 0){  // 奇数层，遍历从左往右，下一层从右往左遍历，因此应从左往右将子节点压入栈中
                if(pNode->left != nullptr){
                    levels[next].push(pNode->left);
                }
                if(pNode->right != nullptr){
                    levels[next].push(pNode->right);
                }
            }else{             // 偶数层，遍历从右往左，下一层从左往右遍历，因此应从右往左将子节点压入栈中
                if(pNode->right != nullptr){
                    levels[next].push(pNode->right);
                }
                if(pNode->left != nullptr){
                    levels[next].push(pNode->left);
                }
            }

            if(levels[current].empty()){     // 当前层处理完
                //cout << endl;
                res.push_back(level);
                level.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }// end while

        return res;
    }



    // 方法2：递归法，使用一个全局 vector 存储结果
    vector<vector<int> > levels;
    vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
        if(root == nullptr){
            return levels;
        }
        zigzagLevelOrder2(root, 0);
        return levels;
    }
    void zigzagLevelOrder2(TreeNode* root, int level) {
        if(levels.size() == level ){
            levels.push_back(vector<int> {});
        }
        if(level % 2 == 0){   // 第1、3、5即奇数层，从左向右遍历，因此直接插入vector 尾部
            levels[level].push_back(root->val);
        }else{                // 第2、4、6即偶数层，从右向左遍历，因此插入 vector 首部
            levels[level].insert(levels[level].begin(), root->val);
        }

        if(root->left != nullptr){
            zigzagLevelOrder2(root->left, level + 1);
        }
        if(root->right != nullptr){
            zigzagLevelOrder2(root->right, level + 1);
        }
    }
};

int main(){

	return 0;
}
