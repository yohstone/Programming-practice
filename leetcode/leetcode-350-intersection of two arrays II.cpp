#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/* Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * Example 2:
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Note:
 *
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 */


class Solution{
public:

    // 方法：直接在vector中查找相同元素
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        // 遍历小vector就行
        if( nums1.size() > nums2.size() ){
            swap(nums1, nums2);
        }
        for(int i=0; i<nums1.size(); i++){
            vector<int>::iterator iter;
            iter = find(nums2.begin(), nums2.end(), nums1[i]);
            if( iter != nums2.end() ){
                res.push_back(nums1[i]);
                nums2.erase( iter );
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,2,3,4,5};
    vector<int> nums2 = {1,1,2,2,3,6};
    vector<int> res;
    res = s.intersection(nums1, nums2);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}
