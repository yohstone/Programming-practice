#include <iostream>
using namespace std;

typedef struct LinkListNode{
    int data;
    LinkListNode* next;
    LinkListNode(int x):data(x),next(nullptr){}
}LinkList;
LinkListNode* reverseDoubleNode(LinkListNode* head){
    if(head == nullptr){
        return head;
    }
    LinkListNode* dummyHead = new LinkListNode(0);
    dummyHead->next = head;
    LinkListNode* cur = head;
    LinkListNode* pre = dummyHead;
    while(cur != nullptr){
        LinkListNode* temp = cur->next->next;
        cur->next->next = cur;
        pre->next = cur->next;
        cur->next = temp;
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
    cout << "Hello World!" << endl;
}
