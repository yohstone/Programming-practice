#include<iostream>
using namespace std;

//    给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//    k 是一个正整数，它的值小于或等于链表的长度。
//    如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//    示例 :
//    给定这个链表：1->2->3->4->5
//
//    当 k = 2 时，应当返回: 2->1->4->3->5
//
//    当 k = 3 时，应当返回: 3->2->1->4->5
//
//    说明 :
//    你的算法只能使用常数的额外空间。
//    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//    k is a positive integer and is less than or equal to the length of the linked list.
//    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//    Example:
//    Given this linked list: 1->2->3->4->5
//
//    For k = 2, you should return: 2->1->4->3->5
//
//    For k = 3, you should return: 3->2->1->4->5
//
//    Note:
//    Only constant extra memory is allowed.
//    You may not alter the values in the list's nodes, only nodes itself may be changed.


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：遍历链表，以 k 为子链表的长度单位进行断开和翻转，将翻转后的子链表的头结点和尾结点存入 vector 中，最后遍历 vector 连接子链表
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        vector<pair<ListNode*, ListNode*> >head_tail;
        ListNode* curr_head = head;      // 待翻转部分链表的头结点
        ListNode* new_head = nullptr;    // 用于存储翻转后的头结点
        ListNode* remain_head = nullptr; // 用于存储未翻转部分的头结点
        ListNode* p = head;              // 用于遍历链表
        int curr_num = 0;
        while(p){
            ++curr_num;
            if(curr_num == k){
                remain_head = p->next;
                p->next = nullptr;    // 断开与后面结点的连接，便于翻转
                new_head = reverseList(curr_head);
                head_tail.push_back({new_head, curr_head});
                curr_head = remain_head;
                curr_num = 0;
                p = remain_head;
            }else{
                p = p->next;
            }
        }
        if(curr_num < k){
            head_tail.push_back({curr_head, nullptr}); // 将剩余不满 k 个结点的部分存入
        }
        for(int i = 0; i < head_tail.size() - 1; ++i){
            head_tail[i].second->next = head_tail[i + 1].first;  // 将翻转好的子链表连接起来
        }
        return head_tail[0].first;
    }
    // 迭代法翻转链表
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    // 方法2：使用翻转链表中第 m 到 n 个结点的算法，直接进行翻转
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* p = head;
        int start = 1, curr_num = 0;
        while(p){
            ++curr_num;
            p = p->next;
            if(curr_num == k){
                head = reverseBetween(head, start, start + k);
                start = start + k + 1;
                curr_num = 0;
            }
        }
        return head;
    }

    // 迭代法翻转链表中第 m 到 n 个结点 1 <= m <= n <= head.size()
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || n == m){
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
};

int main(){
    return 0;
}
