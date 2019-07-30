#include<iostream>
#include<vector>
using namespace std;


/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Example:
 *
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // 暴力法1：遍历所有链表，依次将较小的插入到新链表中 时间复杂度 O(kn) 打败5%
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0){
            return NULL;
        }
        if(len == 1){
            return lists[0];
        }
        ListNode* res_list_head = new ListNode(0);     // 结果链表头指针
        ListNode* res_list_tail = res_list_head;       // 结果链表尾指针，用于插入结点
        int cur_min_index = 0;                         // 当前待插入的最小值所属链表的在lists中的下标
        int valid_num = len;                           // 统计当前有效的头结点数，用于结束循环，初始为链表总数
        while(valid_num > 0){                          // 当所有链表的头结点为NULL时结束循环
            for(int i = 0; i < len; i++){
                if(lists[i] == NULL){
                    valid_num--;
                    continue;
                }else if(lists[cur_min_index] != NULL){
                    if(lists[i]->val < lists[cur_min_index]->val){ // 寻找待插入头结点的最小头结点
                        cur_min_index = i;
                    }
                }else{
                    cur_min_index = i;                 // 当lists[cur_min_index] == NULL时，重新赋予一个有效初值
                }
            }
            if(lists[cur_min_index] != NULL){
                ListNode* temp_node = new ListNode(lists[cur_min_index]->val);    // 新结点
                res_list_tail->next =  temp_node;                                 // 向结果链表中插入新结点
                res_list_tail = res_list_tail->next;
                lists[cur_min_index] = lists[cur_min_index]->next;                // 删除该链表头结点
                valid_num = len;                                                  // 初始化
            }

        }
        return res_list_head->next;
    }

//     暴力法2：先将链表中的值放入vector中，然后对vector排序，最后根据排序后的结果创建一个新的链表
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//
//    }
//
//
    // 两两合并法：先两个链表两个链表的合并，最终合成一个链表 时间复杂度  打败28%
    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0){
           return NULL;
        }
        for(int i = 1; i < len; i ++){
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }

    // 合并两个链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *t = new ListNode(0);
        ListNode *res_list = t;
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
        return res_list->next;
    }


};

int main(){


    return 0;
}

