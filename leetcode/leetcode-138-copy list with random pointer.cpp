#include<iostream>
#include<map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    // 方法1：先遍历一遍，使用 next 建立一个新链表，然后给每个结点的 random 指针赋值
    // 每次给 random 赋值都需要遍历一次新链表，寻找random 在新链表的位置，时间复杂度为 O(n^2) 空间复杂度为 O(1)
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* new_head = new Node(0, nullptr, nullptr);
        Node* p1 = head;
        Node* p2 = new_head;
        while(p1 != nullptr){ // 先使用 next 创建好新链表
            p2->next = new Node(p1->val, nullptr, nullptr);
            p2 = p2->next;
            p1 = p1->next;
        }
        p1 = head;
        p2 = new_head->next;
        while(p1 != nullptr){ // 遍历旧链表的每个结点，为新链表每个结点的 random 指针赋值
            Node* tmp = new_head->next;
            while(p1->random != nullptr && tmp != nullptr){ // 遍历新链表的每个结点，以确定 random 结点的位置
                if(tmp->val != p1->random->val ){
                    tmp = tmp->next;
                }else{
                    p2->random = tmp;
                    break;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return new_head->next;
    }

    // 方法2：先遍历一遍，使用 next 建立一个新链表，并将新结点与旧结点的对应关系存入一个哈希表中，然后使用哈希表给每个结点的 random 指针赋值
    // 每次给 random 赋值只需要查询哈希表，时间复杂度为 O(n) 空间复杂度为 O(n)
    Node* copyRandomList2(Node* head) {
        if(head == nullptr) return head;
        Node* new_head = new Node(0, nullptr, nullptr);
        Node* p1 = head;
        Node* p2 = new_head;
        map<Node*, Node*> nodes_map;
        while(p1 != nullptr){ // 先使用 next 创建好新链表
            p2->next = new Node(p1->val, nullptr, nullptr);
            nodes_map[p1] = p2;
            p2 = p2->next;
            p1 = p1->next;
        }
        p1 = head;
        p2 = new_head->next;
        while(p1 != nullptr){ // 遍历旧链表的每个结点，为新链表每个结点的 random 指针赋值
            p2->random = nodes_map[p1->random];
            p1 = p1->next;
            p2 = p2->next;
        }
        return new_head->next;
    }


    // 方法3：先遍历一遍，将创建的新结点连接在旧结点的后面，然后遍历第二遍，为新节点的 random 赋值，
    // 最后断开链表，奇数位置上的为旧链表，偶数位置上的为新链表，
    // 时间复杂度为 O(n) 空间复杂度为 O(1)
    Node* copyRandomList3(Node* head) {
        if(head == nullptr) return head;
        Node* p1 = head;      // 用于遍历原链表

        while(p1 != nullptr){ // 将创建的新结点插入旧结点之后
            Node* new_node = new Node(p1->val, nullptr, nullptr);
            new_node->next = p1->next;
            p1->next = new_node;
            p1 = new_node->next;
        }

        p1 = head;
        while(p1 != nullptr){ // 为每个结点的 random 指针赋值
            if(p1->random != nullptr){
                p1->next->random = p1->random->next;
            }
            p1 = p1->next->next;
        }

        p1 = head;
        Node* new_head = head->next;  // 新链表的头部
        Node* p2 = new_head;          // 用于遍历新链表
        while(p1 != nullptr && p2->next != nullptr){         // 断开链表
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = nullptr;  // 必须加，因为最后是 p2->next 终止循环， p1->next 尚未获得 nullptr 值
        return new_head;
    }
};

int main(){
    Solution s;

    return 0;
}
