#include<iostream>
#include<vector>
using namespace std;

//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
//
//说明:
//1 ≤ m ≤ n ≤ 链表长度。
//
//示例:
//
//输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL
//
//
//
//Reverse a linked list from position m to n. Do it in one-pass.
//
//Note: 1 ≤ m ≤ n ≤ length of list.




// Definition for a binary tree node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：迭代修改结点的指针
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        for(int i = 0; i < m - 1; ++i){  // 找到开始反转的结点
            pre = pre->next;
            cur = cur->next;
        }
        for(int i = m; i < n; i++){      // 从第 m 个结点开始，反转 n - m 次
            ListNode* tempNode = cur->next;
            cur->next = tempNode->next;
            tempNode->next = pre->next;
            pre->next = tempNode;
        }
        return dummyHead->next;
    }

    // 方法2：迭代修改结点的值, 时间复杂度略高同时需要额外存储空间
    ListNode* reverseBetween2(ListNode* head, int m, int n) {
        if(head == nullptr){
            return head;
        }
        ListNode* cur = head;
        int len = n - m + 1;             // 需要反转的结点数
        vector<int> nodeValues;

        for(int i = 0; i < m - 1; ++i){  // 找到开始反转的结点
            cur = cur->next;
        }
        ListNode* cur2 = cur;
        for(int i = 0; i < len && cur2 != nullptr; i++){      // 从第 m 个结点开始，存下需要反转的结点的值
            nodeValues.push_back(cur2->val);
            cur2 = cur2->next;
        }
        for(int i = 0; i < len && cur != nullptr; i++){      // 从第 m 个结点开始，反转 n - m 次
            cur->val = nodeValues[len - 1 - i];
            cur = cur->next;
        }
        return head;
    }
};


int main(){

	return 0;
}
