#include<iostream>
using namespace std;

//    给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
//    你应当保留两个分区中每个节点的初始相对位置。
//
//    示例:
//
//    输入: head = 1->4->3->2->5->2, x = 3
//    输出: 1->2->2->4->3->5
//
//    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//    You should preserve the original relative order of the nodes in each of the two partitions.
//
//    Example:
//
//    Input: head = 1->4->3->2->5->2, x = 3
//    Output: 1->2->2->4->3->5





// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1，将原链表拆成两个链表，再将两个链表连接起来。
    // 将小于 x 的结点插入 left 链表尾部，将大于等于 x 的结点插入 right 链表尾部。
    ListNode* partition(ListNode* head, int x) {
        ListNode *left_head, *left_tail;
        ListNode *right_head, *right_tail;
        left_head = left_tail = new ListNode(0);
        right_head = right_tail = new ListNode(0);
        while(head != nullptr){
            if(head->val < x){
                left_tail->next = head;
                left_tail = left_tail->next;
            }else{
                right_tail->next = head;
                right_tail = right_tail->next;
            }
            head = head->next;
        }
        left_tail->next = right_head->next;
        right_tail->next = nullptr;  // 最后这一步必须要加，否则会出现环形链表。
        return left_head->next;
    }
};

int main(){
    Solution s;

    return 0;
}
