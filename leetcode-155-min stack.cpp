#include<iostream>
#include<vector>
using namespace std;

//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.


// 为什么 MinStack minStack = new MinStack(); 报错，必须把new去掉才行？
// vector插入不能用nums[numsTop] = x ，需用 nums.insert(nums.begin()+numsTop, x)

// 方法1 用两个数组实现，一个数组存储所有插入的值，另一个数组存储最小值的索引
class MinStack{
private:
    vector<int> nums;
    vector<int> mins;
    int numsTop; // 元素数组顶部指针
    int minsTop; // 最小值数组顶部指针
public:
    MinStack(){
        numsTop = 0;
        minsTop = 0;
    }
    void push(int x){
        nums.insert(nums.begin()+numsTop, x);
        numsTop ++;
        if(minsTop == 0 || x <= mins[minsTop-1]){
            mins.insert(mins.begin()+minsTop, x);
            minsTop++;
        }
    }
    void pop(){
        if( nums[numsTop-1] == mins[minsTop-1]){
            mins.erase( mins.begin() + minsTop - 1 );
            minsTop--;
        }
        nums.erase( nums.begin() + numsTop - 1 );
        numsTop--;
    }
    int top(){
        return nums[numsTop-1];
    }
    int getMin(){
        return mins[minsTop-1];
    }

};
// 方法2， 用双栈实现，细节和方法1的双数组类似
// ......

int main(){

    MinStack minStack =  MinStack();
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    cout << minStack.getMin() << endl;   //--> 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl;      //--> 返回 0.
    cout << minStack.getMin() << endl;   //--> 返回 -2.

    return 0;
}
