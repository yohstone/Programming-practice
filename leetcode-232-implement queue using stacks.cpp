#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/* Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Example:
 *
 * MyQueue queue = new MyQueue();
 *
 * queue.push(1);
 * queue.push(2);
 * queue.peek();  // returns 1
 * queue.pop();   // returns 1
 * queue.empty(); // returns false
 */

// 方法， 两个栈实现
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        // 栈底元素为队列的首部元素
        if(s.size() == 0){
            frontValue = x;
        }
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int sSize = s.size();
        int res = frontValue;
        // 将栈底以上的元素暂放入另一个栈中
        while(sSize > 1){
            tmp.push( s.top() );
            s.pop();
            sSize--;
        }
        // 移除栈底元素
        s.pop();
        // 将元素放回栈
        while(tmp.size() > 0){
            if(s.size() == 0){
                frontValue = tmp.top();
            }
            s.push( tmp.top() );
            tmp.pop();
        }
        return res;
    }

    /** Get the front element. */
    int peek() {
        return frontValue;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(s.size() == 0) return true;
        else return false;
    }
private:
    stack<int> s, tmp;
    int frontValue;
};




int main(){

    return 0;
}
