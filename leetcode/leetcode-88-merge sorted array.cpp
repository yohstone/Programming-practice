#include<iostream>
#include<vector>
using namespace std;

//    给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//    说明:
//
//    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//    示例:
//
//    输入:
//    nums1 = [1,2,3,0,0,0], m = 3
//    nums2 = [2,5,6],       n = 3
//
//    输出: [1,2,2,3,5,6]
//
//    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//    Note:
//
//    The number of elements initialized in nums1 and nums2 are m and n respectively.
//    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.



class Solution {
public:
    // 方法1：从 num1 尾部开始合并，从后往前，不断比较 num1, num2 的尾部元素，
    // 将较大的先添加到合并后的 num1 的尾部
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;              // 合并后的数组的索引
        int p1 = m - 1, p2 = n - 1;     // num1 和 num2 的索引
        if(m == 0) {
            nums1.swap(nums2);
            return ;
        }
        while( p >= 0 && p2 >= 0 ) {
            if( p1 >= 0 && nums1[p1] > nums2[p2] ) {
                nums1[p] = nums1[p1];
                nums1[p1] = 0;
                p1--;
            } else {
                nums1[p] = nums2[p2];
                nums2[p2] = 0;
                p2--;
            }
            p--;
        }
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, nums2.size());
    for(int i = 0; i < nums1.size(); i++)
        cout << nums1[i] << endl;

    return 0;
}
