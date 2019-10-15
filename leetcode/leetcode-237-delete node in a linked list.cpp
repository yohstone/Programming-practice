#include<iostream>
#include<vector>
using namespace std;

//Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//
//Example 1:
//
//Input: head = [4,5,1,9], node = 5
//Output: [4,1,9]
//Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
//Example 2:
//
//Input: head = [4,5,1,9], node = 1
//Output: [4,5,9]
//Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.



struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};


class Solution{
public:
    // 无法获取到node前一个节点的值，因此只能将当前节点的值替换为下一个节点的值以达到删除效果
    void deleteNode(ListNode* node){
        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete(temp);// 释放空间避免内存泄漏
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,5,1,9};
    ListNode *tail = (ListNode*)malloc(sizeof(ListNode));
    ListNode *head = tail;
    ListNode* test = (ListNode*)malloc(sizeof(ListNode));

    for(int i=0;i<nums.size(); i++){
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = nums[i];
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
        if( nums[i] == 4 ){
            test = node;
        }
    }
    s.deleteNode(test);
    ListNode *n = head->next;
    while(n){
        cout << n->val << endl;
        n = n->next;
    }
    return 0;
}
