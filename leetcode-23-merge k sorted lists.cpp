#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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

    // 方法1：暴力法1：遍历所有链表，依次将较小的插入到新链表中 时间复杂度 O(kn) 1150ms 打败5%
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
                res_list_tail->next = new ListNode(lists[cur_min_index]->val);     // 向结果链表中插入新结点
                res_list_tail = res_list_tail->next;
                lists[cur_min_index] = lists[cur_min_index]->next;                // 删除该链表头结点
                valid_num = len;                                                  // 初始化
            }

        }
        return res_list_head->next;
    }

    // 方法2：暴力法2：先将链表中的值放入vector中，然后对vector排序，最后根据排序后的结果创建一个新的链表 时间复杂度 O(nlogn)，36ms 打败92%
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        vector<int> nums;
        int len = lists.size();
        ListNode* res_list_head = new ListNode(0);
        ListNode* res_list_tail = res_list_head;
        if(len == 0){
            return NULL;
        }
        if(len == 1){
            return lists[0];
        }
        for(int i = 0; i < len; i++){           // 将链表中的值放入vector中
            ListNode* l = lists[i];
            while(l){
                nums.push_back(l->val);
                l = l->next;
            }
        }
        sort(nums.begin(), nums.end());         // 排序
        for(int i = 0; i < nums.size(); i++){   // 创建新链表
            res_list_tail->next = new ListNode(nums[i]);
            res_list_tail = res_list_tail->next;
        }
        return res_list_head->next;
    }


    // 方法3：两两合并法：先两个链表两个链表的合并，最终合成一个链表 时间复杂度约O(kn) 300ms左右  打败28%
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

    // 合并两个链表，迭代法较快
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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

    // 方法4：采用分治法优化两两合并法：先两个链表两个链表的合并，最终合成一个链表 时间复杂度约O(kn) 36ms左右  打败89%
    ListNode* mergeKLists4(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0){
           return NULL;
        }
        int left = 0, right = len - 1;          // 左右指针，采用首尾俩链表合并的方法
        while(right > 0){                       // 最终所有的链表合并到 lists[0] 中
            left = left < right ? left : 0;
            lists[left] = mergeTwoLists(lists[left], lists[right]);
            left++;
            right--;
        }
        return lists[0];
    }



    // 方法5：优先队列（堆）法, 先将链表的头结点取出，放入优先队列中，然后从优先队列取出头结点建立新的链表，时间复杂度O(nlogk),48ms,打败64%
    struct cmp{
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;               // 小顶堆
        }
    };
     ListNode* mergeKLists5(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0){
           return NULL;
        }
        ListNode* res_list_head = new ListNode(0);
        ListNode* res_list_tail = res_list_head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(int i = 0; i < len; i++){                               // 将链表中的头结点放入优先队列
            if(lists[i] != NULL){
                heap.push(lists[i]);
            }
        }
        while(!heap.empty()){                                       // 依次取出最小头结点发入新链表中
            ListNode* temp_node = heap.top();
            res_list_tail->next = new ListNode(temp_node->val);
            res_list_tail = res_list_tail->next;
            heap.pop();                                             // 将该头结点从优先队列中删除
            temp_node = temp_node->next;                            // 若该头结点之后还有结点，则之后的结点为新头结点
            if(temp_node != NULL){                                  // 将新头结点放入优先队列
                heap.push(temp_node);
            }
        }
        return res_list_head->next;
    }


};

int main(){


    return 0;
}

