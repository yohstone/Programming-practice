#include<iostream>
#include<vector>
using namespace std;

// Write a program to find the node at which the intersection of two singly linked lists begins.


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：先将一个链表放入 set ，然后遍历另一个链表，若发现同一结点则该结点是交点  156ms 7.6%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        set<ListNode*> visited;
        while(headA){
            visited.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(visited.find(headB) != visited.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
    
    // 方法2：双指针法，设两个指针分别指向这两个链表，若其中一个指针到达链表尾部，则让它指向另一个链表。
    //       当两个指针指向的结点相同时，该结点为交点。 因为你俩指针会走过相同长度的路程最后在交点相遇 56ms 98%
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2){
            p1 = (p1 == NULL) ? headB : p1->next;
            p2 = (p2 == NULL) ? headA : p2->next;
        }

        return p1;
    }
};

int main(){

    return 0;
}
