#include<iostream>
#include<vector>
using namespace std;

/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * Example:
 *
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 */


class Solution{
public:
    // 方法，遇到非零就将其放到前面
    void moveZeros(vector<int>& nums){
        int numCount = 0;
        for(int i=0; i<nums.size(); i++){
            if( nums[i] != 0 ){
                nums[ numCount ] = nums[i];
                if( numCount != i )
                    nums[i] = 0;
                numCount++;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeros( nums );
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}
