#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//    对链表进行插入排序。
//
//    插入排序算法：
//        插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//        每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//        重复直到所有输入数据插入完为止。
//         
//    示例 1：
//    输入: 4->2->1->3
//    输出: 1->2->3->4
//
//    示例 2：
//    输入: -1->5->3->4->0
//    输出: -1->0->3->4->5
//
//    Sort a linked list using insertion sort.
//
//    Algorithm of Insertion Sort:
//        Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
//        At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
//        It repeats until no input elements remain.
//
//    Example 1:
//    Input: 4->2->1->3
//    Output: 1->2->3->4
//
//    Example 2:
//    Input: -1->5->3->4->0
//    Output: -1->0->3->4->5



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 方法1：初始化已排序的链表为头结点，然后依次取后面的结点插入到已排序的链表
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* sorted_list_head = head;
        ListNode* p = head->next;  // 用于遍历未排序结点
        head->next = nullptr;      // 将已排序的结点与未排序的结点断开
        while(p){
            ListNode* temp_node = p->next;
            p->next = nullptr;     // 断开 p 与未排序的结点的连接
            sorted_list_head = insertionSortList(sorted_list_head, p); // 将 p 插入已排序链表
            p = temp_node;         // 移到下一个未排序结点
        }
        return sorted_list_head;

    }
    // 将待插结点 node 插入已排好序的链表
    ListNode* insertionSortList(ListNode* sorted_list_head, ListNode* node){
        ListNode* dummy_head = new ListNode(0);     // 虚拟头结点，便于 node 最小时直接插到头部
        dummy_head->next   = sorted_list_head;
        ListNode* cur_node = sorted_list_head;
        ListNode* pre_node = dummy_head;
        while(cur_node){
            if(node->val < cur_node->val ){         // 小于当前结点则插入当前结点前面
                pre_node->next = node;
                node->next = cur_node;
                break;
            }else if(cur_node->next == nullptr){    // 不小于当前结点，且当前结点为已排序链表最后一个结点，则插入到链表最后
                cur_node->next = node;
                break;
            }
            else{
                pre_node = cur_node;
                cur_node = cur_node->next;
            }
        }
        return dummy_head->next;
    }
};


int main(){

	return 0;
}
