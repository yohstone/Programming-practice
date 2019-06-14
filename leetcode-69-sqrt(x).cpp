#include<iostream>
using namespace std;

/* Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 *
 * Example 1:
 *
 * Input: 4
 * Output: 2
 * Example 2:
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 *              the decimal part is truncated, 2 is returned.
 */


class Solution{
public:
    // 方法1：普通暴力  48ms
    int mySqrt1(int x){
        long long i=0;
        long long res;
        long long nextRes;
        if( x == 0 || x == 1) return x;
        for(i=1; i <= x/2+1; i++){ // 平方根不可能大于x/2+1
            res = i*i;
            nextRes = (i+1)*(i+1);
            if( res <= x && nextRes > x )
                break;
        }
        return i;
    }

    // 方法2：二分法  8ms
    int mySqrt2(int x){
        int left, right;
        if( x == 0 || x == 1) return x;
        left = 1;
        right = x/2 + 1;
        while(left <= right){
            long long mid = ( left + right )/2;
            long long res = mid * mid;
            if( res == x ) return mid;
            else if( res < x )
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
//     方法3： 牛顿法  由于符号易混淆，令n表示输入的x，需要求的是 x^2 - n = 0 时的x值，设函数f(x)= x^2 - n; (n是已知值)
//     则f`(x) = 2x; 函数f(x)图像上的没一点的斜率都为2x；则所求值即为函数 f(x)与X轴正半轴的交点的x值，
//     可用导数f`(x)的直线与X轴的交点无限逼近所求值。 因为该交点处的 x` = x- f(x)/2x; 化简可得所求的 x` = (x + n/x)/2;     4ms
    int mySqrt3(int x){
        double res = 1;
        if( x == 0 || x == 1) return x;
        while( fabs( res*res - x ) > 0.5){
            res = ( res + x/res)/2;
        }
        return int(res);
    }
};
int main(){
    Solution s;
    int x;
    while(cin >> x){
        cout << s.mySqrt2(x) << endl;
    }
    return 0;
}
