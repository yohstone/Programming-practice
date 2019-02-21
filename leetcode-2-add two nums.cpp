
#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* l1_node = l1;
		ListNode* l2_node = l2;
    	ListNode* l3_node; //current node 
    	ListNode* l3_head;
    	int num1,num2,sum,carry=0;
		l3_head = new ListNode(0);
		l3_node = l3_head;
        while(l1_node != NULL or l2_node !=NULL){
        	
//			if(l1_node == NULL){
//				num1 = 0;
//				num2 = l2_node->val;
//				l2_node = l2_node->next;
//			}else if(l2_node == NULL){
//				num1 = l1_node->val;
//				num2 = 0;
//				l1_node = l1_node->next;
//			}else{
//				num1 = l1_node->val;
//				num2 = l2_node->val;
//				l1_node = l1_node->next;
//				l2_node = l2_node->next;
//			}
			num1 = l1_node ? l1_node->val : 0;
			num2 = l2_node ? l2_node->val : 0; 
			sum = num1+num2+carry;
//			if(sum >= 10){
//				l3_node->val = sum % 10;
//				carry = 1;
//			}else{
//				l3_node->val = sum ;
//				carry = 0;
//			}
			carry = sum /10;
			l3_node->next = new ListNode(sum%10);
			l3_node = l3_node->next;
			if(l1_node != NULL) l1_node = l1_node->next;
			if(l2_node != NULL) l2_node = l2_node->next;
		}
		if(carry > 0 ){
			l3_node->next = new ListNode(carry);
			
		}
		return l3_head->next;
    }
};
int main(){
	ListNode* l1;
	ListNode* l2;
	ListNode* l3;
	ListNode* l1_tail;
	ListNode* l2_tail;
	ListNode* node1;
	ListNode* node2;
	int a[] = {1};
	int b[] = {9,9};
	l1 =  (ListNode *)new ListNode(0);
	l2 =  (ListNode *)new ListNode(0);
	l1_tail =  (ListNode *)new ListNode(0);
	l2_tail =  (ListNode *)new ListNode(0);
	for(int i=0; i<sizeof(a)/sizeof(a[0]);i++){
		node1 =  (ListNode *)new ListNode(0);
		if(i == 0){
			node1->val = a[i];
			l1 = node1;
			l1_tail = node1;
		}else{
			node1->val = a[i];
			l1_tail->next = node1;
			l1_tail = node1;
		}
	}
	for(int i=0; i<sizeof(b)/sizeof(b[0]);i++){
		node2 =  (ListNode *)new ListNode(0);
		if(i == 0){
			node2->val = b[i];
			l2 = node2;
			l2_tail = node2;
		}else{
			node2->val = b[i];
			l2_tail->next = node2;
			l2_tail = node2;
		}
	}
	Solution *s = new Solution;
	l3 = s->addTwoNumbers(l1,l2);
	node1 =  (ListNode *)new ListNode(0);
	node1 = l3;
	while(node1 != NULL){
		cout << node1->val << ' ';
		node1 = node1->next;
	}
	
}

