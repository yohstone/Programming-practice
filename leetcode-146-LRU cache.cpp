#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
//
//获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
//写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
//
//进阶:
//
//你是否可以在 O(1) 时间复杂度内完成这两种操作？
//
//示例:
//
//LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // 返回  1
//cache.put(3, 3);    // 该操作会使得密钥 2 作废
//cache.get(2);       // 返回 -1 (未找到)
//cache.put(4, 4);    // 该操作会使得密钥 1 作废
//cache.get(1);       // 返回 -1 (未找到)
//cache.get(3);       // 返回  3
//cache.get(4);       // 返回  4
//
//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//The cache is initialized with a positive capacity.
//
//Follow up:
//Could you do both operations in O(1) time complexity?



class LRUCache {
private:
    int capacity;
    list<pair<int, int>> recentList;
    unordered_map<int, list<pair<int, int>>::iterator > dataPos; // 存储数据在链表里的位置(迭代器)

public:
    LRUCache(int capacity) : capacity(capacity){

    }

    int get(int key) {
        if(dataPos.find(key) != dataPos.end()){
            put(key, dataPos[key]->second);               // 若数据存在，直接调用 put 函数更新数据的位置
            return dataPos[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if(dataPos.find(key) != dataPos.end()){       // 若链表中存在该数据
            recentList.erase(dataPos[key]);           // 将被访问的数据的结点删除
        }else if(recentList.size() >= capacity){      // 若数据不存在且链表空间已满
            dataPos.erase(recentList.back().first);
            recentList.pop_back();                    // 将链表尾部（最久未访问）的结点及其位置数据删除
        }
        recentList.push_front({key, value});          // 将新数据插入链表头部
        dataPos[key] = recentList.begin();            // 存下新数据的位置（迭代器）
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){

	return 0;
}
