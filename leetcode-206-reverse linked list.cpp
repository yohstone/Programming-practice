#include<iostream>
#include<vector>
using namespace std;

/* Reverse a singly linked list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 方法1 ： 迭代法
    ListNode* reverseList1(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr){
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    // 方法2 ： 递归法
    ListNode* reverseList2(ListNode* head) {
        if( head == NULL || head->next == NULL ) return head;
        ListNode *newHead = reverseList2(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    ListNode *head, *tail;
    head = tail = (ListNode *)malloc(sizeof(ListNode));
    for(int i=0; i<nums.size(); i++){
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->val = nums[i];
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    ListNode *p = head;
    cout << "before reverse" << endl;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }

    p = s.reverseList2(head);
    cout << "after reverse" << endl;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
