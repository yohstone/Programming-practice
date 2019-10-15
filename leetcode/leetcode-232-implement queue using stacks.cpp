#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <exception>
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

// 方法1， 两个栈实现，一个栈1 s 用于存储数据，另一个栈2 tmp 用于弹出数据时的临时容器。
// 实现 queue 中的弹出操作时，先把栈底元素上面的元素暂时放入 tmp ，然后弹出栈底元素，最后把 tmp 中的元素重新压入 s。
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        // 栈底元素为队列的首部元素
        if(s.size() == 0){
            frontElem = x;
        }
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int sSize = s.size();
        int res = frontElem;
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
                frontElem = tmp.top();
            }
            s.push( tmp.top() );
            tmp.pop();
        }
        return res;
    }

    /** Get the front element. */
    int peek() {
        return frontElem;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(s.size() == 0) return true;
        else return false;
    }
private:
    stack<int> s, tmp;
    int frontElem;
};


// 方法2， 两个栈实现，一个栈 stack1 用于压入数据，另一个栈 stack2 用于弹出数据。
// 实现 queue 中的弹出操作时，先判断 stack2 是否为空，若为空，将 stack1 的数据压入 stack2，
// 当 stack2 不为空时，直接弹出 stack2 的栈顶元素。
// 此方法较方法1 省略了在弹出元素之后将数据重新压回栈1的操作，同时两个栈都可以用于存储数据，空间更大。
class MyQueue2 {
public:
    /** Initialize your data structure here. */
    MyQueue2() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if(stack1.size() == 0){         // 栈1为空时，记录下栈1的栈底元素
            stack1Base = x;
            if(stack2.size() == 0){     // 栈2也为空，则 x 为队列首部元素
                frontElem = x;
            }
        }
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = frontElem;
        if(stack2.size() <= 0){
            // 将栈1 stack1 中的元素压入 stack2，这样顺序就倒过来了
            while(stack1.size() > 0){
                stack2.push( stack1.top() );
                stack1.pop();
            }
            stack1Base = -1;  // 更新 stack1 的栈底元素
        }
//        if(stack2.size() == 0){
//            throw new exception("queue is empty!");
//        }
        stack2.pop();
        if(stack2.size() > 0){          // 更新队列首元素的值
            frontElem = stack2.top();
        }else{
            frontElem = stack1Base;
        }
        return res;
    }

    /** Get the front element. */
    int peek() {
        return frontElem;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(stack1.size() == 0 && stack2.size() == 0) return true;
        else return false;
    }
private:
    int frontElem;    // 队首元素
    int stack1Base;   // stack1 的栈底元素
    stack<int> stack1, stack2;
};


// 方法2 的模板实现
template<typename T>
class MyQueue3 {
private:
    T frontElem;    // 队首元素
    T stack1Base;   // stack1 的栈底元素
    stack<T> stack1, stack2;
public:
    /** Initialize your data structure here. */
    MyQueue3() {

    }

    /** Push element x to the back of queue. */
    void push(T x) {
        if(stack1.size() == 0){         // 栈1为空时，记录下栈1的栈底元素
            stack1Base = x;
            if(stack2.size() == 0){     // 栈2也为空，则 x 为队列首部元素
                frontElem = x;
            }
        }
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    T pop() {
        T res = frontElem;
        if(stack2.size() <= 0){
            // 将栈1 stack1 中的元素压入 stack2，这样顺序就倒过来了
            while(stack1.size() > 0){
                stack2.push( stack1.top() );
                stack1.pop();
            }
            stack1Base = -1;  // 更新 stack1 的栈底元素
        }
//        if(stack2.size() == 0){
//            throw new exception("queue is empty!");
//        }
        stack2.pop();
        if(stack2.size() > 0){          // 更新队列首元素的值
            frontElem = stack2.top();
        }else{
            frontElem = stack1Base;
        }
        return res;
    }

    /** Get the front element. */
    T peek() {
        return frontElem;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(stack1.size() == 0 && stack2.size() == 0) return true;
        else return false;
    }

};


int main(){

    return 0;
}
