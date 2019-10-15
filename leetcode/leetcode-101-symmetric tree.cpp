#include<iostream>
#include<stack>
using namespace std;

/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *  
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 */



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    // 方法1：另创建方法递归实现
    bool isSymmetric(TreeNode* root){
        return isSymmetricTree(root, root);
    }
    bool isSymmetricTree(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }else if(left == NULL || right == NULL){
            return false;
        }else{
            return left->val == right->val && isSymmetricTree(left->left, right->right)
                    && isSymmetricTree(left->right, right->left);
        }
    }

    // 方法2：迭代实现
    bool isSymmetic2(TreeNode* root){
        stack<TreeNode *> s;
        s.push(root);
        s.push(root);
        while(!s.empty()){
            TreeNode* n1 = s.top();
            s.pop();
            TreeNode* n2 = s.top();
            s.pop();
            if(n1 == NULL && n2 == NULL){
                continue
            }else if(n1 == NULL || n2 == NULL){
                return false;
            }else{
                if(n1->val != n2->val){
                    return false;
                }
                s.push(n1->left);
                s.push(n2->right);
                s.push(n1->right);
                s.push(n2->left);
            }
        }
        return true;
    }
};
int main(){
    return 0;
}
