#include <iostream>
using namespace std;
// 题目：给你一个单链表，翻转链表里的每一对结点
// 如，给你 1 2 3 4，返回 2 1 4 3
//
// 漏问的问题：如果链表结点数量是奇数该如何处理

// 链表结点的定义
typedef struct LinkListNode{
    int data;
    LinkListNode* next;
    LinkListNode(int x):data(x),next(nullptr){}
}LinkList;

// 翻转链表中的每一对结点
LinkListNode* reverseDoubleNode(LinkListNode* head){
    if(head == nullptr){
        return head;
    }
    LinkListNode* dummyHead = new LinkListNode(0); // 头结点前的虚假头结点
    dummyHead->next = head;
    LinkListNode* cur = head;
    LinkListNode* pre = dummyHead;
    while(cur != nullptr){
        LinkListNode* temp = cur->next->next; // 暂存俩节点之后的那个节点
        cur->next->next = cur;                // 修改后一个节点的指针指向当前结点
        pre->next = cur->next;                // 倆结点的上一节点的指针指向倆结点中的后一结点
        cur->next = temp;                     // 当前结点的指针指向暂存结点

        pre = cur;
        cur = temp;
    }
    return dummyHead->next;
}
int main() {
    int nums[] = {1,2,3,4};
    LinkListNode* head = new LinkListNode(0);
    LinkListNode* p = head;

    for(int i = 0; i < 4; i++){
        LinkListNode* newNode = new LinkListNode(nums[i]);
        p->next = newNode;
        p = newNode;
        //cout << p->data << ' ';
    }
    LinkListNode* newHead = reverseDoubleNode(head->next);

    while(newHead != nullptr){
        cout << newHead->data << ' ';
        newHead = newHead->next;
    }
    //cout << "Hello World!" << endl;
}
