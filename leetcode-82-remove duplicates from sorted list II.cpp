#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

/* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * Example 1:
 *
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * Example 2:
 *
 * Input: 1->1->1->2->3
 * Output: 2->3
 */



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：当当前节点与前后节点不相等时，该节点是非重复元素，把非重复的节点放到一个新的链表中
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL || head->next == NULL ) return head;
        ListNode* newHead = NULL;
        ListNode* node; // 用于创建新链表
        ListNode* pre  = NULL;
        ListNode* now  = head;
        ListNode* next = head->next;
        while(now){
            cout << "out "<< now->val << endl;
            if( (pre == NULL || pre->val != now->val)
              && (next == NULL || next->val != now->val) ){
                // 将非重复元素放到新链表中
                if(newHead == NULL ){
                    //node = (ListNode*)malloc(sizeof(ListNode));
                    node = new ListNode(now->val);
                    newHead = node;
                    cout << "creat" << endl;
                }else{
                    cout << "in "<< now->val << endl;
                    node->next = new ListNode(now->val);
                    node = node->next;
                }
            }
            pre = now;
            now = next;
            if(next)
                next = next->next;
        }
        return newHead;
    }

    // 方法2：先在head之前加一个空节点，然后开始遍历，在原链表上删除重复元素
    ListNode* deleteDuplicates2(ListNode* head) {
        if( head == NULL || head->next == NULL ) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next  = head;

        ListNode *p  = newHead;
        ListNode *pre, *now;

        // p从空节点开始遍历，防止第一个节点就是重复元素
        while(p->next){
            pre = p->next;
            now = pre;
            while( now->next && pre->val == now->next->val){
                now = now->next;
            }
            // 根据now是否移动来判断是否遇到了重复元素
            if(pre == now){
                p = p->next;
            }else{
                p->next = now->next;
            }
        }
        return newHead->next;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,3,4}; //{1,2,3,3,4,4,5};
    ListNode *head, *p;
    p = (ListNode*)malloc(sizeof(ListNode));
    p = new ListNode(nums[0]);
    head = p;
    for(int i=1; i<nums.size(); i++){
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        node = new ListNode(nums[i]);
        p->next = node;
        p = node;
    }
    head = s.deleteDuplicates2(head);
    p = head;
    while(p){
        cout << p->val  << " -> ";
        p = p->next;
    }

    return 0;
}
