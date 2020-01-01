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
    // 方法1 ：递归，因为是二叉搜索树，所以可以通过比较大小来判断 p , q 位于当前结点的左子树还是右子树
//    1. 从根节点开始遍历树
//    2. 如果节点 p 和节点 q 都在右子树上，那么以右孩子为根节点继续 1 的操作
//    3. 如果节点 p 和节点 q 都在左子树上，那么以左孩子为根节点继续 1 的操作
//    4. 如果条件 2 和条件 3 都不成立，这就意味着我们已经找到节 p 和节点 q 的 LCA 了
//    时间复杂度 O(logN) ~ O(N) 空间复杂度 O(logN) ~ O(N) 最坏的情况需要遍历整棵树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val){           // p, q 位于左子树
            return lowestCommonAncestor(root->left, p, q);
        }else if(p->val > root->val && q->val > root->val){     // p, q 位于右子树
            return lowestCommonAncestor(root->right, p, q);
        }else{
            return root;
        }
    }
    // 方法2 : 迭代法
    // 时间复杂度 O(logN) ~ O(N) 空间复杂度 O(1) 最坏的情况需要遍历整棵树
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != nullptr){
            if(p->val < root->val && q->val < root->val){       // p, q 位于左子树
                root = root->left;
            }else if(p->val > root->val && q->val > root->val ){// p, q 位于右子树
                root = root->right;
            }else{
                return root;
            }
        }
        return nullptr;
    }
};


int main(){

	return 0;
}
