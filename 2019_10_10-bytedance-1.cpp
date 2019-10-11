#include <iostream>
using namespace std;
// 题目：给你一个单链表，翻转链表里的每一对结点
// 如，给你 1 2 3 4，返回 2 1 4 3
//
// 漏问的问题：
//  1. 如果链表结点数量是奇数该如何处理
//  2. 通过修改结点的值还是通过修改结点的指针来进行反转？

// 链表结点的定义
typedef struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x):data(x),next(nullptr){}
}LinkList;

// 面试时的原方法：翻转链表中的每一对结点
ListNode* reverseDoubleNode(ListNode* head){
    if(head == nullptr){
        return head;
    }
    ListNode* dummyHead = new ListNode(0);    // 头结点前的虚假头结点
    dummyHead->next = head;
    ListNode* cur = head;
    ListNode* pre = dummyHead;
    while(cur != nullptr){
        if(cur->next == nullptr){
            break;
        }
        ListNode* temp = cur->next->next;     // 暂存俩节点之后的那个节点
        cur->next->next = cur;                // 修改后一个节点的指针指向当前结点
        pre->next = cur->next;                // 倆结点的上一节点的指针指向倆结点中的后一结点
        cur->next = temp;                     // 当前结点的指针指向暂存结点

        pre = cur;
        cur = temp;
    }
    return dummyHead->next;
}

// 方法2：翻转链表中的每一对结点，temp 的取值不同，与 leetcode-92 的方法类似
ListNode* reverseDoubleNode2(ListNode* head){
    if(head == nullptr){
        return head;
    }
    ListNode* dummyHead = new ListNode(0);    // 头结点前的虚假头结点
    dummyHead->next = head;
    ListNode* cur = head;
    ListNode* pre = dummyHead;
    while(cur != nullptr){
        if(cur->next == nullptr){
            break;
        }
        ListNode* tempNode = cur->next;
        cur->next = tempNode->next;
        tempNode->next = pre->next;
        pre->next = tempNode;

        cout << pre->data << ' ' << cur->data << endl;
        pre = pre->next;
        cur = cur->next;
    }
    return dummyHead->next;
}

int main() {
    int nums[] = {1,2,3};
    ListNode* head = new ListNode(0);
    ListNode* p = head;

    for(int i = 0; i < 3; i++){
        ListNode* newNode = new ListNode(nums[i]);
        p->next = newNode;
        p = newNode;
        //cout << p->data << ' ';
    }
    ListNode* newHead = reverseDoubleNode2(head->next);

    while(newHead != nullptr){
        cout << newHead->data << ' ';
        newHead = newHead->next;
    }
    //cout << "Hello World!" << endl;
}
