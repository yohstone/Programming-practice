#include<iostream>
#include<vector>
using namespace std;
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    //方法1
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode *t = new ListNode(0);
        ListNode *new_list = t;
        while( l1 && l2 ){
            if( l1->val <= l2->val ){
                t->next = l1;
                l1 = l1->next;
            }else{
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        if(l1 != NULL)
            t->next = l1;
        if(l2 != NULL)
            t->next = l2;
        return new_list->next;
    }
    //方法2 递归
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists2(l1, l2->next);
            return l2;
        }
    }
};
int main(){
    Solution s;
    ListNode *head1, *head2, *head3, *l1, *l2;
    vector<int> a1 = {1,2,4};
    vector<int> a2 = {1,3,4};
    l1 = new ListNode(0);
    l2 = new ListNode(0);
    head1 = l1;
    head2 = l2;
    for(int i=0; i<a1.size(); i++){
        l1->next = new ListNode(a1[i]);
        l1 = l1->next;
    }
    for(int i=0; i<a2.size(); i++){
        l2->next = new ListNode(a2[i]);
        l2 = l2->next;
    }
    head3 = s.mergeTwoLists2(head1->next, head2->next);
    while(head3){
        cout <<head3->val << endl;
        head3 = head3->next;
    }
    return 0;
}
