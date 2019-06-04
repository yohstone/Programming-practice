#include<iostream>
#include<vector>
using namespace std;

//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//
//The number of elements initialized in nums1 and nums2 are m and n respectively.
//You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//Example:
//
//Input:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//Output: [1,2,2,3,5,6]


class Solution{
public:
    // 从num1尾部开始合并
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int p = m + n - 1;
        int p1 = m-1, p2 = n-1;
        if(m == 0){
            nums1.swap(nums2);
            return ;
        }
        while( p >= 0 && p2 >= 0 ){
            if( nums1[p1] > nums2[p2] ){
                nums1[p] = nums1[p1];
                nums1[p1] = 0;
                p1--;
            }else{
                nums1[p] = nums2[p2];
                nums2[p2] = 0;
                p2--;
            }
            p--;
        }
    }
};
int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, nums2.size());
    for(int i=0; i< nums1.size(); i++)
        cout << nums1[i] << endl;

    return 0;
}
