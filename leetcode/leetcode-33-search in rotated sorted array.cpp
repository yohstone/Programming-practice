#include<iostream>
using namespace std;

class Solution {
public:

    // 方法1： 二分查找法   最快 4ms 91%
    int search1(vector<int>& nums, int target) {
        int left  = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])){
                 left = mid + 1;
            }
            else{
                 right = mid;
            }
        }
        return left == right && nums[left] == target ? left : -1;
    }
};

int main(){
    return 0;
}
