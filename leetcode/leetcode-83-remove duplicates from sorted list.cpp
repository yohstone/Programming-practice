#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

/* Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * Example 1:
 *
 * Input: 1->1->2
 * Output: 1->2
 * Example 2:
 *
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p=head;
        while( p != NULL && p->next != NULL ){
            if( p->val == p->next->val ){
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        return head;
    }
};

int main(){

    return 0;
}
