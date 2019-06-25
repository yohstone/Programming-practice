#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/* Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Example:
 *
 * MyStack stack = new MyStack();
 *
 * stack.push(1);
 * stack.push(2);
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 */


// 方法1：只用一个队列
class MyStack {
public:

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        reverse(q);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        int res = q.front();
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.size() == 0) return true;
        else return false;
    }
    // 将最后一个元素放到队列的第一位
    void reverse(queue<int> &q){
        int qSize = q.size();
        while(qSize > 1){
            q.push(q.front());
            q.pop();
            qSize--;
        }
    }
private:
    queue<int> q;
};


// 方法2：两个队列实现，需要一个变量存储top的值
class MyStack2 {
public:

    /** Initialize your data structure here. */
    MyStack2() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        topValue = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int qSize = q.size();
        int res = topValue;
        // 把队列最后一个元素之前的元素放到tmp中
        while(qSize > 1){
            tmp.push(q.front());
            topValue = q.front();
            qSize--;
            q.pop();
        }
        q.pop()
        swap(q, tmp);
        return res;
    }

    /** Get the top element. */
    int top() {
        return topValue;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.size() == 0) return true;
        else return false;
    }

private:
    queue<int> q, tmp;
    int topValue;
};



int main(){

    return 0;
}
