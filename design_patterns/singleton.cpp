#include<iostream>

using namespace std;

// 单例 - 懒汉模式
class Singleton{
private:
    Singleton(){};
    static Singleton *instance;

public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }

private:
    class Garbo{           // 它的唯一工作就是在析构函数中删除Singleton的实例
    public:
        ~Garbo(){
            if(Singleton::instance != nullptr){
                delete Singleton::instance;
                Singleton::instance = nullptr;
            }
        };
    };
    static Garbo garbo;    // 定义一个静态成员，在程序结束时，系统会调用它的析构函数
};


// 单例 - 饿汉模式
class Singleton2{
private:
    Singleton2(){};
    static Singleton2* instance;

public:
    static Singleton2* getInstance(){
        return instance;
    }

private:
    class Garbo{
    public:
        ~Garbo(){
            if(Singleton2::instance != nullptr){
                delete Singleton2::instance;
                Singleton2::instance = nullptr;
            }
        }
    };
    static Garbo garbo;


};
Singleton2* Singleton2::instance = new Singleton2();

// 单例 - 饿汉模式另一种实现方式，局部静态不需要析构函数？适合单线程
//class Singleton2{
//private:
//    Singleton2(){}
//public:
//    static Singleton2* getInstance(){
//        static Singleton2 instance;
//        return &instance;
//    }
//};

// 单例 - 多线程下的单例模式（主要处理懒汉模式）
class Singleton3{
private:
    static Singleton3* instance;
    Singleton3(){}
public:
    static Singleton3* getInstance(){
        if(instance == nullptr){
            Lock();     // 根据自己需要进行设计
            if(instance == nullptr){
                instance = new Singleton3();
            }
            UnLock();   // 根据自己需要进行设计
        }
        return instance;
    }

private:

    class Garbo{
    public:
        ~Garbo(){
            if(Singleton3::instance != nullptr){
                cout << "delete singleton" << endl;
                delete Singleton3::instance;
                Singleton3::instance = nullptr;
            }
        };
    };
    static Garbo garbo;
};



int main() {
    return 0;
}

