#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/* Given a linked list, rotate the list to the right by k places, where k is non-negative.
 *
 * Example 1:
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * Example 2:
 *
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：将链表连成环并计算链表长度 len ，然后在第 len - (k % len) 个结点处将链表断开，此结点作为新链表的尾结点
    // 设结点数为 n 则时间复杂度为 O(n) ~ O(2n)之间 16ms 打败60%
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL ){
           return head;
        }
        ListNode* p = head;
        int len = 0;                    // 链表长度
        while(p->next != NULL){         // 寻找链表尾结点并统计链表长度
            len++;
            p = p->next;
        }
        len++;
        p->next = head;                 // 链表连成环
        int times = len - (k % len);    // 旋转次数，因为旋转 len 次后又变回原来的链表，所以实际只需旋转 len - (k % len)次
        p = head;
        while(times-- > 1){             // 寻找第 len - (k % len)个结点
            p = p->next;
        }
        head = p->next;                 // 新的头结点
        p->next = NULL;                 // 断开环
        return head;
    }

    // 方法2：双端队列，将链表放入双端队列里并计算链表长度 len ，然后在旋转 k % len 次（因为双端队列能直接把尾元素放到最前面），再拼成链表返回
    // 设结点数为 n 则时间复杂度为 O(2n) ~ O(3n)之间  最快8ms 98%
    ListNode* rotateRight2(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL){
           return head;
        }
        deque<int> dque;
        ListNode* p = head;                 // 用于遍历链表
        int len = 0;                        // 链表长度
        while(p != NULL){                   // 寻找链表尾结点并统计链表长度
            dque.push_back(p->val);
            len++;
            p = p->next;
        }
        int times = k % len;                // 旋转次数，因为旋转 len 次后又变回原来的链表，所以实际只需旋转 k % len 次
        while(times--){                     // 不断将尾元素插入队列最前方
            int temp = dque.back();
            dque.pop_back();
            dque.push_front(temp);
        }
        p = head;
        while(p != NULL){               // 更新原链表中每个结点的val
            p->val = dque.front();
            dque.pop_front();
            p = p->next;
        }
        return head;
    }
};


int main(){
    return 0;
}
