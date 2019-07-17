#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 */



 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
