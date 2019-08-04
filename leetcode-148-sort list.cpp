#include<iostream>
using namespace std;


/* Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * Example 2:
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：归并排序法，先将链表切成单个结点，然后自底向上两两合并
    // 时间复杂度 O( n + nlogn) 约为 O(nlogn) ，空间复杂度 O(1)。 64ms 打败 89%
    ListNode* sortList(ListNode* head) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        int sub_len  = 1;           // 当前子链表长度
        int list_len = 0;
        ListNode* p  = head;
        while(p != NULL){           // 统计链表长度
            list_len++;
            p = p->next;
        }

        while(sub_len < list_len){
            ListNode* cut_res = dummy_head->next;       // 存储切割后剩下的链表，初始为整个链表
            ListNode* tail = dummy_head;

            while(cut_res != NULL){
                ListNode* l1 = cut_res;
                ListNode* l2 = cutList(l1, sub_len);    // 切割后 l1 为长度 sub_len 的子链表
                cut_res = cutList(l2, sub_len);         // 切割后 l2 为长度 sub_len 的子链表

                tail->next = mergeList(l1, l2);         // 合并 l1, l2

                while(tail->next != NULL){              // 保持 tail 在最后
                    tail = tail->next;
                }
            }
            sub_len *= 2;
        }
        return dummy_head->next;

    }

    // 链表切割函数，将链表的前 k 个结点切下来，并返回后半部分的链表
    ListNode* cutList(ListNode* head, int k){
        ListNode* p = head;
        while(k-- && p != NULL){
            p = p->next;
        }
        if(p == NULL){
            return NULL;
        }
        ListNode* res = p->next;
        p->next = NULL;
        return res;
    }

    // 合并两个有序链表为一个有序链表，按结点值从小到大排序
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode(0);
        ListNode* tail = res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){      // 若 l1 结点小，先插入 l1 结点
                tail->next = l1;
                tail = tail->next;
                l1  = l1->next;
            }else{
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        if(l1 != NULL){                 // l1 未遍历完
            tail->next = l1;
        }else{                          // l2 未遍历完
            tail->next = l2;
        }
        ListNode* p = res->next;
        while(p){
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
        return res->next;
    }
};

int main(){

	return 0;
}
