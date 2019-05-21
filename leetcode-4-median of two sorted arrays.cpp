#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;
class Solution {
public:
    //����2������������������λ��������һ�㻯Ϊ����������������ϲ���ĵ�k��������k = (m+n)/2ʱΪԭ����Ľ⡣
    //��˷ֱ������һ������A�͵ڶ�������B�ĵ�k/2����a��b��Ȼ��Ƚ�a��b����a<b, ˵����k����λ��A����ĵ�k/2�������Σ�
    //����B����ĵ�k/2����ǰ��Σ������ģ��С��һ�룬Ȼ��ݹ鴦�� ʱ�临�Ӷ��� O(log(m+n))
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size(), n = nums2.size();
        int mid1 = (m + n + 1)/2, mid2 = (m + n + 2)/2;
        //���ǵ���������ż�ԣ��Ƚ�������������mid1 == mid2������Ϊ����ֻ����ҵ�(m + n + 1)/2������������Ҫȡ�м�������ƽ������Ϊ��λ��
        if (mid1 == mid2)
            return findKth(nums1, 0, nums2, 0, mid1)/1.0;
        else
            return (findKth(nums1, 0, nums2, 0, mid1) + findKth(nums1, 0, nums2, 0, mid2))/2.0;
    }

    //Ѱ�ҵ�k����
    int findKth(vector<int>& nums1, int begin1, vector<int>& nums2, int begin2, int k) {
        //��begin1��begin2�������鳤�ȣ����ʱ��k����Ϊ��һ������ĵ�k����
        if (begin1 >= nums1.size()) return nums2[begin2 + k - 1];
        if (begin2 >= nums2.size()) return nums1[begin1 + k - 1];
        //��kΪ1ʱ��nums1��num2����С���Ǹ���Ϊ��1����
        if (k == 1) return min(nums1[begin1], nums2[begin2]);
        //�ֱ��������������ĵ� k/2 ��Ԫ��
        //�������1�ĵ�k/2����С������2�ĵ�k/2��������ʾ�ܵĵ�k����λ������1�ĵ�k/2�����ĺ��Σ�����������2�ĵ�k/2������ǰ���
        //�������1�ĵ�k/2�������ڵ�������2�ĵ�k/2��������ʾ�ܵĵ�k����λ������1�ĵ�k/2������ǰ��Σ�����������2�ĵ�k/2�����ĺ���
        //���ڷ�Χ��С��k/2��������ʱ�ܵĵ�k����ʵ���ϵ����µķ�Χ�ڵĵ�k-(k/2)���������εݹ�
        int mid1 = (begin1 + k/2 -1) < nums1.size() ? nums1[begin1 + k/2 -1] : INT_MAX;
        int mid2 = (begin2 + k/2 -1) < nums2.size() ? nums2[begin2 + k/2 -1] : INT_MAX;
        if (mid1 < mid2)
            return findKth(nums1, begin1 + k/2, nums2, begin2, k - k/2);
        else
            return findKth(nums1, begin1, nums2, begin2 + k/2, k - k/2);
    }
    //����1��������������nums1��nums2�ϲ���Ȼ��ֱ������λ�������Ӷ�ΪO(m+n+1)����O(m+n)
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    	int index2=0;
    	vector<int> nums3(0);
    	double median=0;
    	int m_index=0;
    	//�ϲ����鵽nums3
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
		//������������nums3����λ��
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
