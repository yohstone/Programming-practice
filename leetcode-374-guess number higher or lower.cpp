//We are playing the Guess Game. The game is as follows:
//
//I pick a number from 1 to n. You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
//You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
//
//-1 : My number is lower
//1 : My number is higher
//0 : Congrats! You got it!


#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
static int pick;
class Solution {
public:
    // 二分查找法
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int mid = ( left + right )/2 ;
        int res = guess(mid);
        while( res != 0){
            if(res == 1){
                left = mid + 1;
            }else if(res == -1){
                right = mid - 1;
            }
            mid = ( left + right )/2 ;
            res = guess(mid);
        }
        return mid;
    }
};

int main(int argc, const char * argv[]) {
    pick = 88;
    Solution s;
    
    cout << s.guessNumber(100) << endl;
    return 0;
}

int guess(int num){
    if(num < pick) return 1;
    else if(num > pick) return -1;
    else return 0;
}
