#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int N;
    vector<long long> nums;
    cin >> N;
    while(N--){
        long long num;
        cin >> num;
        nums.push_back(num);
    }
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    double avg  = ((double)(nums[i] + nums[i+1] + nums[i+2]))/ 3.0; // 求平均值
    double res =  ( (nums[i] - avg)*(nums[i] - avg) +  (nums[i+1] - avg)*(nums[i+1] - avg) + (nums[i+2] - avg)*(nums[i+2] - avg)  )/3.0;
    for(i = 1; i < len - 2; i++){
        //cout << nums[i] << " " << nums[i+1] << " " << nums[i+2] << endl;
        double avg  = ((double)(nums[i] + nums[i+1] + nums[i+2]))/ 3.0; // 求平均值
        //cout << avg << endl;
        double intval = ( (nums[i] - avg)*(nums[i] - avg) +  (nums[i+1] - avg)*(nums[i+1] - avg) + (nums[i+2] - avg)*(nums[i+2] - avg)  )/3.0;
        //cout << intval << endl;
        if(intval < res){
            res = intval;
        }
    }
    printf("%.2f\n", res);
    return 0;
}
