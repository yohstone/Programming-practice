#include<iostream>
#include<set>
using namespace std;

/* Given a linked list, determine if it has a cycle in it.
 *
 * To represent a cycle in the given linked list, we use an integer pos which represents the
 * position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 */


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
    // 方法1：哈希表法，记录下遍历过的节点
    bool hasCycle1(ListNode *head){
        set<ListNode*> hset;
        while(head){
            if( hset.find(head) != hset.end() ){
                return true;
            }else{
                hset.insert(head);
            }
            head = head->next;
        }
        return false;
    }

    // 方法2：双指针法，使用快慢指针进行遍历
    bool hasCycle2(ListNode *head){
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while( slow != fast){
            if(fast == NULL || fast->next == NULL){  // 若不存在环，快指针会最先到达链表尾部
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }

    // 方法3：先反转链表，然后比较头指针是否相等，相等则有环，因为若有环，头结点会被反转两次，从何与原来一样
    bool hasCycle3(ListNode *head){
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode *head_temp = head;                 // 先存下原链表的头指针
        head = reverseList(head);                   // 反转链表
        if( head == head_temp ){
            return true;
        }
        else{
            return false;
        }
    }
    // 迭代反转链表
    ListNode* reverseList(ListNode* head) {
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
};
int main(){
    return 0;
}
