#include<iostream>
using namespace std;

/* Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 *
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：建立一个虚拟头结点，直接遍历删除 最快40ms 78%
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* last_node = dummy_head;
        while(head){
            if(head->val == val){
                last_node->next = head->next;
            }else{
                last_node = head;
            }
            head = head->next;
        }
        return dummy_head->next;

    }

    // 方法2：递归删除  36ms 94%
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr){
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }

};
int main() {

    return 0;
}
