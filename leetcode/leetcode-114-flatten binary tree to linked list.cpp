#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//    给定一个二叉树，原地将它展开为链表。
//
//    例如，给定二叉树
//
//        1
//       / \
//      2   5
//     / \   \
//    3   4   6
//    将其展开为：
//
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
//
//    Given a binary tree, flatten it to a linked list in-place.
//
//    For example, given the following tree:
//
//        1
//       / \
//      2   5
//     / \   \
//    3   4   6
//    The flattened tree should look like:
//
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：使用先序遍历，先暂存右子树，然后把左子树放到右子树的位置
    // 在把原来的右子树放到原来的左子树的最右边结点，迭代实现
    void flatten(TreeNode* root) {
        while(root != nullptr){
            if(root->left != nullptr){      // 左子树存在时才需要操作
                TreeNode* p = root->left;
                while(p->right != nullptr){ // 找到左子树的最右结点
                    p = p->right;
                }
                p->right = root->right;     // 右子树接到左子树的最右结点处
                root->right = root->left;   // 左子树放到右子树的位置
                root->left  = nullptr;
            }else{
                root = root->right;
            }
        }
    }

    // 方法2：使用变型的后序遍历（先右再左再根），即依次遍历 6,5,4,3,2,1
    // 然后每遍历一个结点就将当前结点的右指针修改为上一个结点，如 6 <- 5 <- 4 3 2 1
    // 递归实现
    TreeNode* pre_node = nullptr;
    void flatten2(TreeNode* root) {
        if(root == nullptr){
            return ;
        }
        flatten2(root->right);
        flatten2(root->left);
        root->right = pre_node;
        root->left  = nullptr;   // 后序遍历，左子树已遍历过，所以可以直接置为nullptr
        pre_node = root;
    }
    // 方法2：后序遍历迭代实现（先左再右再根）
    void flatten2_(TreeNode* root) {
        if(root == nullptr){
            return ;
        }
        stack<TreeNode*> st;
        TreeNode* cur_node = root;
        TreeNode* pre_node = nullptr;
        while(cur_node != nullptr || !st.empty()){
            while(cur_node != nullptr){
                st.push(cur_node);              // 添加根结点
                cur_node = cur_node->right;     // 递归添加右结点
            }
            cur_node = st.top();
            if(cur_node->left == nullptr || cur_node->left == pre_node){ // 左结点为空或左结点已访问过，则可以修改当前结点
                st.pop();
                cur_node->right = pre_node;
                cur_node->left = nullptr;
                pre_node = cur_node;
                cur_node = nullptr;
            }else{                              // 左结点未访问过，先访问左节点
                cur_node = cur_node->left;
            }
        }
    }

    // 方法3：先序遍历，迭代实现，将右孩子暂存入栈中，将上一结点的右指针指向当前结点
    void flatten3(TreeNode* root) {
        if(root == nullptr){
            return ;
        }
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* pre_node = nullptr;
        while(!st.empty()){
            TreeNode* cur_node = st.top();
            st.pop();
            if(pre_node != nullptr){            // 使上一节点的右指针指向当前结点
                pre_node->right = cur_node;
                pre_node->left  = nullptr;
            }

            if(cur_node->right != nullptr){     // 将右子树压入栈
                st.push(cur_node->right);
            }
            if(cur_node->left != nullptr){      // 将左子树压入栈，使得先访问左子树，因为是先序遍历
                st.push(cur_node->left);
            }
            pre_node = cur_node;
        }
    }

};
int main(){

	return 0;
}
