#include<iostream>
using namespace std;

class Solution{
public:
    // 方法1： 迭代，击败100%。。。
    bool isPowerOfFour(int num){
        if(num == 1){
            return true;
        }else if(num > 1 && num % 4 == 0){
            num /= 4;
            while(num > 1){
                if(num % 4 != 0){
                    return false;
                }
                num /= 4;
            }
            return true;
        }else{
            return false;
        }
    }
    // 方法2： 2的幂次方的二进制是只有一个1，其余都是0，而4的幂次方是1都在奇数位置上，
    // 所以可以用一个只有奇数位上有1的二进制数与4的幂次方作运算,结果还是4的幂次方，
    // 因为是32位数，所以这个二进制数为1010101010101010101010101010101，即0x55555555
    // 也可以在2的幂次方基础上使用 num % 3 == 1 来判断是否是4的幂次方。
    // 由于 4=3+1， 那么4的N次方就是（3+1）^N，尝试展开多项式，
    // 比如(3+1)^2 =(3+1)*(3+1)，除了1*1以外永远都有3相乘，
    // 再展开3次方，(3+1)*(3+1)*(3+1)，结论一致，除了结尾的1都有3相乘，
    // 因此可以有结论，一个数的N次方-1总能除尽比这个数小1的数。 即 (x^n - 1) % (n-1) == 0
    bool isPowerOfFour2(int num){
        if(num == 1){
            return true;
        }else if(num > 1 && (num & (num - 1) == 0) && num & 0x55555555 == num){ // 或 && num % 3 == 1){ // num & (num - 1) == 0  num必为2的幂次方
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    return 0;
}
