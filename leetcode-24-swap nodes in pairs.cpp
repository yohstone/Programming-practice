#include<iostream>
using namespace std;

/* Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 *
 * Example:
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：迭代直接法，设置 3 个结点指针分别指向当前待交换的结点以及第一个待交换结点的前一结点。修改结点的 next 值完成交换
    // 时间复杂度 O(n) 空间复杂度 O(1) 8ms 打败 61%
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre_node = new_head;
        ListNode* cur_node = head;
        ListNode* next_node = cur_node->next;
        while(next_node != NULL){               // 每次循环前 next_node 都是最后一个结点
            pre_node->next  = next_node;
            cur_node->next  = next_node->next;
            next_node->next = cur_node;
            if(cur_node->next == NULL){         // 交换后，cur_node为当前 3 个结点的最后一个结点
                break;
            }
            pre_node  = pre_node->next->next;
            cur_node  = cur_node->next;
            next_node = cur_node->next;         // 或 next_node = next_node->next->next->next;
        }
        return new_head->next;
    }



    // 方法2：递归法
    // 时间复杂度 O(n) 空间复杂度 O(1) 0ms 打败 100%
    ListNode* swapPairs2(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        p1->next = swapPairs2(p2->next);
        p2->next = p1;
        return p2;              // 交换后 p2 为头
    }
};

int main(){
    return 0;
}
