#include<iostream>
using namespace std;

/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // l1，l2分别表示两个数，每个数以倒叙存于链表中，链表每个结点存一位数字
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_node = l1;
        ListNode* l2_node = l2;
        ListNode* l3_node;                      // 结果链表的当前结点
        ListNode* l3_head;                      // 结果链表头部
        int num1, num2, sum, carry = 0;
        l3_head = new ListNode(0);
        l3_node = l3_head;

        while(l1_node != NULL or l2_node != NULL) {
            num1  = l1_node ? l1_node->val : 0;
            num2  = l2_node ? l2_node->val : 0;
            sum   = num1 + num2 + carry;                // 从个位开始计算每一位之和以及进位
            carry = sum / 10;
            l3_node->next = new ListNode(sum % 10);     // 将结果放入结果链表中
            l3_node = l3_node->next;
            if(l1_node != NULL)
                l1_node = l1_node->next;
            if(l2_node != NULL)
                l2_node = l2_node->next;
        }
        if(carry > 0 ) {
            l3_node->next = new ListNode(carry);

        }
        return l3_head->next;
    }
};
int main() {
    ListNode* l1;
    ListNode* l2;
    ListNode* l3;
    ListNode* l1_tail;
    ListNode* l2_tail;
    ListNode* node1;
    ListNode* node2;
    int a[] = {1};
    int b[] = {9, 9};
    l1 =  (ListNode *)new ListNode(0);
    l2 =  (ListNode *)new ListNode(0);
    l1_tail =  (ListNode *)new ListNode(0);
    l2_tail =  (ListNode *)new ListNode(0);

    // 创建链表 l1
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        node1 =  (ListNode *)new ListNode(0);
        if(i == 0) {
            node1->val = a[i];
            l1 = node1;
            l1_tail = node1;
        } else {
            node1->val = a[i];
            l1_tail->next = node1;
            l1_tail = node1;
        }
    }

    // 创建链表 l2
    for(int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        node2 =  (ListNode *)new ListNode(0);
        if(i == 0) {
            node2->val = b[i];
            l2 = node2;
            l2_tail = node2;
        } else {
            node2->val = b[i];
            l2_tail->next = node2;
            l2_tail = node2;
        }
    }

    // 计算两个链表数之和
    Solution *s = new Solution;
    l3 = s->addTwoNumbers(l1, l2);
    node1 =  (ListNode *)new ListNode(0);
    node1 = l3;

    // 输出计算结果
    while(node1 != NULL) {
        cout << node1->val << ' ';
        node1 = node1->next;
    }

}

