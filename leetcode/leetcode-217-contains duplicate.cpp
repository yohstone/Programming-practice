#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
//
//Example 1:
//
//Input: [1,2,3,1]
//Output: true
//Example 2:
//
//Input: [1,2,3,4]
//Output: false


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numsSet( nums.begin(), nums.end() );
        return numsSet.size() != nums.size();
    }
};
int main(){
    Solution s;
    vector<int> nums = {7,3,2,1,2};
    cout << s.containsDuplicate(nums) <<endl;
    return 0;
}
