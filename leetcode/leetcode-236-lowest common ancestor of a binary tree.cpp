#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

//    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//
//    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
//    例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
//
//           6
//         /   \
//        2     8
//       / \   / \
//      0   4  7  9
//         / \
//        3   5
//
//    示例 1:
//
//    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//    输出: 6
//    解释: 节点 2 和节点 8 的最近公共祖先是 6。
//    示例 2:
//
//    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//    输出: 2
//    解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
//     
//
//    说明:
//
//    所有节点的值都是唯一的。
//    p、q 为不同节点且均存在于给定的二叉搜索树中。
//
//    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
//
//    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two
//    nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//
//    Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]


// LCA: lowest common ancestor

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1 ：递归，判断 p , q 是否在当前结点的左右子树中，
    // 1. 若分别存在左右子树中，则当前结点是最近公共结点，直接返回当前结点
    // 2. 若只存在于当前结点的左子树或右子树中，继续递归左子树或右子树
    // 递归结束条件：当前结点为空或为 p q 中的一个
    //    时间复杂度 O(logN) ~ O(N) 空间复杂度 O(logN) ~ O(N) 最坏的情况需要遍历整棵树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* left  = lowestCommonAncestor(root->left, p, q);   // 判断 p , q 是否存在左子树中
        TreeNode* right = lowestCommonAncestor(root->right, p, q);  // 判断 p , q 是否存在右子树中
        if(left != nullptr && right != nullptr){        //  p , q 分别存在于当前结点的左右子树
            return root;
        }
        return left == nullptr ? right : left;          // 若不同时存在，则返回非空的结点，即返回左子树或右子树的 LCA
    }


    // 方法2 : 先求从根结点到 p , q 的两条路径，可以看成两个链表，然后求两个链表的最后的交点
    // 时间复杂度 O(logN) ~ O(N) 空间复杂度 O(logN) ~ O(N) 最坏的情况需要遍历整棵树
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path, q_path;
        if(!getPath(root, p, p_path) || !getPath(root, q, q_path)){
            return nullptr;                                         // 不存在 P 或 q 的路径，直接返回空指针
        }
        int index = 0;  // 用于遍历两条路径，找到 LCA
        while(index <= p_path.size() - 1 && index <= q_path.size() - 1){
            if(p_path[index] != q_path[index]){
                return p_path[index - 1];
            }
            ++index;
        }
        return p_path[index - 1];   // 或 q_path[index - 1]
    }

    // 获取从根结点到目标结点 target_node 的路径，存入 node_path 中
    bool getPath(TreeNode* root, TreeNode* target_node, vector<TreeNode*>& node_path){
        if(root == nullptr){
            return false;
        }
        node_path.push_back(root);
        if(root == target_node){                                    // 若当前结点就是目标结点，直接返回 true，表示路径已寻找结束
            return true;
        }else if(getPath(root->left, target_node, node_path)){      // 若当前结点不是目标结点，但当前结点的左子树有目标结点
            return true;
        }else if(getPath(root->right, target_node, node_path)){     // 若当前结点不是目标结点，但当前结点的右子树有目标结点
            return true;
        }else{                                                      // 若当前结点的左右子树都不含目标结点，说明到达不了，返回 false
            node_path.pop_back();
            return false;
        }
    }
};


int main(){

	return 0;
}
