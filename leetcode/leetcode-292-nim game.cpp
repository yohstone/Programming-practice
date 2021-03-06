#include<iostream>
using namespace std;

//    你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。
//
//    你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。
//
//    示例:
//
//    输入: 4
//    输出: false
//    解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
//         因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
//
//    You are playing the following Nim Game with your friend:
//    There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones.
//    The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
//    Both of you are very clever and have optimal strategies for the game. Write a function to determine
//    whether you can win the game given the number of stones in the heap.

class Solution{
public:
    // 如果堆中石头的数量 n 不能被 4 整除，那么你总是可以赢得 Nim 游戏的胜利。
    bool canWinNim(int n){
        if( n % 4 == 0) return false;
        else return true;
    }
};
int main(){
    Solution s;
    int n;
    while(cin >> n){
       cout << s.canWinNim(n) << endl;
    }
    return 0;
}
