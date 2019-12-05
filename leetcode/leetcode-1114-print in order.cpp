#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

//    我们提供了一个类：
//
//    public class Foo {
//      public void one() { print("one"); }
//      public void two() { print("two"); }
//      public void three() { print("three"); }
//    }
//    三个不同的线程将会共用一个 Foo 实例。
//
//    线程 A 将会调用 one() 方法
//    线程 B 将会调用 two() 方法
//    线程 C 将会调用 three() 方法
//    请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。
//
//    示例 1:
//
//    输入: [1,2,3]
//    输出: "onetwothree"
//    解释:
//    有三个线程会被异步启动。
//    输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
//    正确的输出是 "onetwothree"。
//    示例 2:
//
//    输入: [1,3,2]
//    输出: "onetwothree"
//    解释:
//    输入 [1,3,2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
//    正确的输出是 "onetwothree"。
//
//    注意:
//    尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
//    你看到的输入格式主要是为了确保测试的全面性。
//
//
//    Suppose we have a class:
//
//    public class Foo {
//      public void first() { print("first"); }
//      public void second() { print("second"); }
//      public void third() { print("third"); }
//    }
//    The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(),
//    and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
//
//    Example 1:
//
//    Input: [1,2,3]
//    Output: "firstsecondthird"
//    Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(),
//    and thread C calls third(). "firstsecondthird" is the correct output.
//    Example 2:
//
//    Input: [1,3,2]
//    Output: "firstsecondthird"
//    Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
//
//    Note:
//    We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seems to imply the ordering.
//    The input format you see is mainly to ensure our tests' comprehensiveness.


// 方法1 ： 互斥锁
class Foo {
public:
    mutex smx;
    mutex tmx;
    Foo() {
        smx.lock();
        tmx.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        smx.unlock();
    }

    void second(function<void()> printSecond) {
        lock_guard<mutex> lg(smx);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        tmx.unlock();
    }

    void third(function<void()> printThird) {
        lock_guard<mutex> lg1(tmx);
        lock_guard<mutex> lg2(smx); // 这一步可以省略
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};


// 方法1 : 互斥锁的另一种方式
class Foo1 {
private:
    mutex f_mutex, s_mutex;

public:
    //初始化两个锁
    Foo1() {
        f_mutex.lock();  //锁1
        s_mutex.lock();  //锁2
    }

    //无需等待
    void first(function<void()> printFirst) {
        printFirst();
        f_mutex.unlock(); //释放锁1，给second放行
    }

    //需等待锁1释放执行
    void second(function<void()> printSecond) {
        f_mutex.lock();
        printSecond();
        f_mutex.unlock();
        s_mutex.unlock(); //释放锁2，给third放行
    }

    //需等待锁2释放执行
    void third(function<void()> printThird) {
        s_mutex.lock();
        printThird();
        s_mutex.unlock();
    }
};


// 方法2 ：成员变量，时间复杂度太高
class Foo2 {
public:
    volatile int flag;
    Foo2() {
        flag = 1;
    }

    void first(function<void()> printFirst) {
        while (flag < 1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 2;
    }

    void second(function<void()> printSecond) {
        while (flag < 2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag = 3;
    }

    void third(function<void()> printThird) {
        while(flag < 3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};


// 方法3 ： 条件变量
class Foo3 {
public:
    Foo3() {

    }

    void first(function<void()> printFirst) {

        std::unique_lock<std::mutex> lk(g_mutex); // 等待直至 main() 发送数据

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        // 通知前完成手动解锁，以避免等待线程才被唤醒就阻塞（细节见 notify_one ）
        counter++;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(g_mutex);

        cv1.wait(lk, [this]() {     // 阻塞当前线程，直到条件变量被唤醒
            return counter == 2;
        });

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        counter++;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(g_mutex);

        cv2.wait(lk, [this]() {
            return counter == 3;
        });

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    int counter = 1;
    std::condition_variable cv1;
    std::condition_variable cv2;
    std::mutex g_mutex;   // 使用lock和unlock手动加锁
};





int main(){
    return 0;
}
