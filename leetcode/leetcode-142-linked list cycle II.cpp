#include<iostream>
#include<vector>
#include<set>
using namespace std;


/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 * Note: Do not modify the linked list.
 *
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 *
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 *
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 *
 * Follow-up:
 * Can you solve it without using extra space?
 */



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1： 使用哈希表的唯一性存下每个遍历过的结点，当再次遇到同一结点时该结点为入口直接返回
    // 时间复杂度 O(n) 空间复杂度 O(n) 最快28ms，打败24%
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited;                         // 已访问过的结点
        while(head){
            if(visited.find(head) != visited.end()){    // 发现重复结点
                return head;
            }else{
                visited.insert(head);
            }
            head = head->next;
        }
        return head;
    }

    // 方法2：使用快慢指针，若存在环，设非环结点为 a 个，环内的结点为 b 个，
    // 则俩指针第一次相遇时快指针已在环内走了 kb + c 步 （ k = 1,2... ，0 <= c < b），且相遇点距入环处有 b - c 个结点
    // 由公式：2 * 慢指针的路程 = 快指针的路程， 可得： 2 * (a + c) = a + kb + c，
    // 化简得 a = (k - 1)b + (b - c)，所以，设两个速度相同的指针分别同时从快慢指针第一次相遇的结点和链表头结点出发，他们最终会相遇于环入口结点。
    // 时间复杂度 O(n) 空间复杂度 O(1) 最快 16ms，打败78%
    ListNode *detectCycle2(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* p1 = hasCycle(head);            // 判断是否有环并指向第一次相遇的结点
        if(p1 == NULL){
            return NULL;
        }
        ListNode* p2 = head;                      // 从头开始的指针
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }

    // 使用快慢指针遍历链表，判断是否有环，有则返回快慢指针的相遇结点
    ListNode* hasCycle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){  // 若不存在环，快指针会最先到达链表尾部
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }
};


int main(){
    return 0;
}
