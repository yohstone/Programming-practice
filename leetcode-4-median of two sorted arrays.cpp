#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;
class Solution {
public:
    //方法2，两个有序数组求中位数，问题一般化为，求两个有序数组合并后的第k个数，当k = (m+n)/2时为原问题的解。
    //因此分别求出第一个数组A和第二个数组B的第k/2个数a和b，然后比较a和b，当a<b, 说明第k个数位于A数组的第k/2个数后半段，
    //或者B数组的第k/2个数前半段，问题规模缩小了一半，然后递归处理。 时间复杂度是 O(log(m+n))
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size(), n = nums2.size();
        int mid1 = (m + n + 1)/2, mid2 = (m + n + 2)/2;
        //考虑到总数的奇偶性，比较这两个数，若mid1 == mid2则总数为奇数只需查找第(m + n + 1)/2个数，否则需要取中间俩数的平均数作为中位数
        if (mid1 == mid2)
            return findKth(nums1, 0, nums2, 0, mid1)/1.0;
        else
            return (findKth(nums1, 0, nums2, 0, mid1) + findKth(nums1, 0, nums2, 0, mid2))/2.0;
    }

    //寻找第k个数
    int findKth(vector<int>& nums1, int begin1, vector<int>& nums2, int begin2, int k) {
        //当begin1或begin2超过数组长度，则此时第k个数为另一个数组的第k个数
        if (begin1 >= nums1.size()) return nums2[begin2 + k - 1];
        if (begin2 >= nums2.size()) return nums1[begin1 + k - 1];
        //当k为1时，nums1和num2中最小的那个数为第1个数
        if (k == 1) return min(nums1[begin1], nums2[begin2]);
        //分别查找这两个数组的第 k/2 个元素
        //如果数组1的第k/2个数小于数组2的第k/2个数，表示总的第k个数位于数组1的第k/2个数的后半段，或者是数组2的第k/2个数的前半段
        //如果数组1的第k/2个数大于等于数组2的第k/2个数，表示总的第k个数位于数组1的第k/2个数的前半段，或者是数组2的第k/2个数的后半段
        //由于范围缩小了k/2个数，此时总的第k个数实际上等于新的范围内的第k-(k/2)个数，依次递归
        int mid1 = (begin1 + k/2 -1) < nums1.size() ? nums1[begin1 + k/2 -1] : INT_MAX;
        int mid2 = (begin2 + k/2 -1) < nums2.size() ? nums2[begin2 + k/2 -1] : INT_MAX;
        if (mid1 < mid2)
            return findKth(nums1, begin1 + k/2, nums2, begin2, k - k/2);
        else
            return findKth(nums1, begin1, nums2, begin2 + k/2, k - k/2);
    }
    //方法1，将俩有序数组nums1与nums2合并，然后直接求中位数，复杂度为O(m+n+1)，即O(m+n)
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    	int index2=0;
    	vector<int> nums3(0);
    	double median=0;
    	int m_index=0;
    	//合并数组到nums3
        for(int index1=0; index1<nums1.size();){
        	if( index2 >= nums2.size() || nums1[index1] <= nums2[index2]){
        		nums3.push_back(nums1[index1]);
        		index1++;
			}else{
				nums3.push_back(nums2[index2]);
				index2++;
			}
		}
		for(; index2<nums2.size(); index2++){
			nums3.push_back(nums2[index2]);
		}
		//计算有序数组nums3的中位数
		m_index = floor(nums3.size()/2);
		if(nums3.size() % 2 == 1){
			median = nums3[ m_index ]/1.0;
		}else{
			median = double((nums3[ m_index ] + nums3[ m_index-1 ] )/2.0 );
		}
		return median;
    }
};
int main(){
	Solution s ;
	vector<int> nums1 = {1,3};
	vector<int> nums2 = {2};
	cout << s.findMedianSortedArrays2(nums1, nums2) << endl;
	return 0;
}
