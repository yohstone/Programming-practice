#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//    在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
//    一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//    计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
//    示例 1:
//    输入: [3,2,3,null,3,null,1]
//
//         3
//        / \
//       2   3
//        \   \
//         3   1
//
//    输出: 7
//    解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
//
//    示例 2:
//    输入: [3,4,5,1,3,null,1]
//
//         3
//        / \
//       4   5
//      / \   \
//     1   3   1
//
//    输出: 9
//    解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
//
//
//    The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root,
//    each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree".
//    It will automatically contact the police if two directly-linked houses were broken into on the same night.
//    Determine the maximum amount of money the thief can rob tonight without alerting the police.


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1： 树型动态规划  + dfs
    // 设 dp(cur) = max(seleted(cur), unselected(cur)) 表示遍历到当前结点时可偷到的最大金额，其中包括当前结点被选择和不被选择两种结果
    // 则 dp(cur) = max( max(dp(cur->left), dp(cur->right)), cur->val + unselected(root->left) + unselected(root->right) )
    // 即 seleted(cur) = max(dp(cur->left), dp(cur->right));
    //    unselected(cur) = cur->val + unselected(root->left) + unselected(root->right);
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return res.first > res.second ? res.first : res.second;
    }
    pair<int, int> dfs(TreeNode* root){
        pair<int, int> selection(0, 0);// selection.first 表示不选当前结点的最大金额，selection.second表示选择当前结点的最大金额
        if(root == nullptr){
            return selection;
        }
        pair<int, int> l_selection = dfs(root->left);
        pair<int, int> r_selection = dfs(root->right);
        selection.first = max(l_selection.first, l_selection.second) + max(r_selection.first, r_selection.second); // 不选当前结点，则当前结点的最大金额是左右子节点的最大金额
        selection.second = root->val + l_selection.first + r_selection.first;                               // 选择当前结点，则左右子节点都不能选
        return selection;
    }

};

int main(){
    Solution s;

    return 0;
}
