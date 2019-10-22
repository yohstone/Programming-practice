#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//示例:
//
//给定有序数组: [-10,-3,0,5,9],
//
//一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
//
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted array: [-10,-3,0,5,9],
//
//One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：递归实现，因为是平衡二叉搜索树，且给的是排好序的链表，所以根结点必然是链表中间的结点（为了平衡），然后二分递归根结点的左右子树
    // 使用快慢指针查找链表的中间结点，时间复杂度 O(NlogN)，空间复杂度 O(logN)
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return new TreeNode(head->val);
        }
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *slow = start, *fast = start, *pre = nullptr; // pre 用于断开链表
        while(fast != nullptr && fast->next != nullptr){       // 查找链表的中间结点，并断开链表
            pre  = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(pre != nullptr){
            pre->next = nullptr;
        }
        TreeNode* root = new TreeNode(slow->val);    // 中间结点为树的根结点
        root->left = sortedListToBST(head);          // 构造左子树
        root->right = sortedListToBST(slow->next);   // 构造右子树
        return root;
    }
    // --- 方法1 end


    // 方法2：递归实现，因为是平衡二叉搜索树，且给的是排好序的链表，所以根结点必然是链表中间的结点（为了平衡），然后二分递归根结点的左右子树
    // 先将链表转换成有序数组，然后使用数组构造平衡BST  时间复杂度：O(N + logN) ，空间复杂度：O(N + logN)
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedListToBST(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedListToBST(vector<int> &nums, int low, int high){
        if(low > high){
            return nullptr;
        }
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedListToBST(nums, low, mid - 1);
        root->right = sortedListToBST(nums, mid + 1, high);
        return root;
    }
    // --- 方法2 end


    // 方法3：递归实现，仿照中序遍历的遍历过程，先构建左子树，再构建根，再构建右子树
    // 需要先计算链表长度  时间复杂度：O(N) 空间复杂度：O(logN)
    ListNode* head;
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* p = head;
        int listLength = 0;
        while(p != nullptr){   // 计算链表长度
            ++listLength;
            p = p->next;
        }
        this->head = head;
        return sortedListToBST(0, listLength - 1);
    }
    // low 与 high 只作为递归终止判断条件
    TreeNode* sortedListToBST(int low, int high){
        if(low > high){
            return nullptr;
        }
        int mid = (low + high) / 2;
        TreeNode* left = sortedListToBST(low, mid - 1);   // 先构建左子树
        TreeNode* root = new TreeNode(this->head->val);         // 再创建根结点
        root->left = left;
        this->head = this->head->next;  // 构建完左半部分时，链表中的头指针将指向根节点或中间节点（它成为根节点）。
                                        // 因此，需使用头指针指向的当前值作为根节点，并将指针后移一位
        root->right = sortedListToBST(mid + 1, high);
        return root;
    }
    // --- 方法3 end

};

int main(){

	return 0;
}
