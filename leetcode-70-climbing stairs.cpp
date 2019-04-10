#include<iostream>
#include<math.h>
using namespace std;
/**
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
**/
class Solution {
public:
    //����1�������ѧ쳲�����ͨ�ʽ��
    int climbStairs(int n){
        double f = sqrt(5);
        int res;
        res = int( (pow((1+f)/2, n+1) - pow( (1-f)/2, n+1) )/ f + 0.5) ;
        return res;
    }
    //����2���ݹ鷽����ʱ�临�Ӷ�̫��
    int climbStairs2(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        return climbStairs2(n-1) + climbStairs2(n-2);
    }
    //����3��������洢쳲���������
    int climbStairs3(int n) {
        int f[n+1];
        f[1] = 1;
        if(n>1) f[2] = 2;
        for(int i=3;i<=n; i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};
int main(){
    Solution s;
    int n;
    while(cin >> n){
        cout << s.climbStairs3(n)<< endl;
    }
    return 0;
}
