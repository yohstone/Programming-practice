#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;


//    我们提供一个类：
//
//    class FooBar {
//      public void foo() {
//        for (int i = 0; i < n; i++) {
//          print("foo");
//        }
//      }
//
//      public void bar() {
//        for (int i = 0; i < n; i++) {
//          print("bar");
//        }
//      }
//    }
//    两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。
//
//    请设计修改程序，以确保 "foobar" 被输出 n 次。
//
//     
//
//    示例 1:
//
//    输入: n = 1
//    输出: "foobar"
//    解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
//    示例 2:
//
//    输入: n = 2
//    输出: "foobarfoobar"
//    解释: "foobar" 将被输出两次。
//
//
//
//    The same instance of FooBar will be passed to two different threads.
//    Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.


// 方法1：交替加互斥锁
class FooBar {
private:
    int n;
    mutex foo_mutex;
    mutex bar_mutex;

public:
    FooBar(int n) {
        this->n = n;
        bar_mutex.lock();
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            foo_mutex.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
        	bar_mutex.unlock();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            bar_mutex.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
        	foo_mutex.unlock();
        }
    }
};


// 方法2：条件变量
class FooBar {
private:
    int n;
    int flag = 1;
    condition_variable cv1;
    condition_variable cv2;
    mutex g_mutex;   // 使用lock和unlock手动加锁

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lk(g_mutex);
        for (int i = 0; i < n; i++) {
            cv1.wait(lk, [this]() {     // 阻塞当前线程，直到条件变量被唤醒
                return flag == 1;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
                printFoo();
        	flag = 2;
        	cv2.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lk(g_mutex);
        for (int i = 0; i < n; i++) {
            cv2.wait(lk, [this]() {     // 阻塞当前线程，直到条件变量被唤醒
                return flag == 2;
            });
        	// printBar() outputs "bar". Do not change or remove this line.
                printBar();
        	flag = 1;
        	cv1.notify_one();
        }
    }
};
int main(){
    return 0;
}
