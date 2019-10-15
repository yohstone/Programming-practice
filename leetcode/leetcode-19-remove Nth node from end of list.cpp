#include<iostream>
using namespace std;

/* Given a linked list, remove the n-th node from the end of list and return its head.
 *
 * Example:
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 *
 * Given n will always be valid.
 */



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 设置快慢指针，快指针先走n+1步，然后慢指针开始一起走，当快指针指向尾部的NULL时，慢指针指向倒数第n+1个指针
    // 同时，设置一个假结点指向头部，以应对列表中只有一个结点，或者需要删除列表的头部等情况。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){                                // 链表为空时，虽然题目中说没这样的情况，以防万一
            return head;
        }
        ListNode* dummy = new ListNode(0);        // 假结点， c语言用：(ListNode *)malloc(sizeof(ListNode));
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for(int i = 0; i < n + 1; i++){           // 快指针先走 n+1 步
            fast = fast->next;
        }
        while(fast != NULL){                      // 一起走
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;            // 删除倒数第 n 个结点
        return dummy->next;
    }
};
int main(){
    return 0;
}
