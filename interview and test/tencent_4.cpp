//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//long operate(vector<long> &nums){
//    int len = nums.size();
//    int i;
//    long minValue;
//    if(len == 1){
//        return nums[0];
//    }
//
//    for(i = 0; i < len; i++){ // 寻找最小值
//        if(nums[i] > 0){
//            minValue = nums[i];
//            break;
//        }
//    }
//    if(i == len){
//        return 0;
//    }
//    for(; i < len; i++){ // 操作3
//        if(nums[i] > 0){
//           nums[i] = nums[i] - minValue;
//        }
//    }
//    return minValue;
//}
//
//int main(){
//    int n;  // 正整数数量
//    int k;  // 操作轮数
//    vector<long> nums;
//    cin >> n >> k;
//    while(n--){
//        long tmp;
//        cin >> tmp;
//        nums.push_back(tmp);
//    }
//    sort(nums.begin(), nums.end());
//    while(k--){
//        long minValue = operate(nums);
//        cout << minValue << endl;
//    }
//}


#include<bits/stdc++.h>
using namespace std;
void help(int *num, int n, int k) {
    int pre = 0;
    sort(num, num + n);
    int i = 0, cnt = 0;
    while(i < n && cnt < k) {
        if(num[i] > pre) {
            cout << num[i] - pre << endl;
            pre = num[i];
            i++;
            cnt++;
        } else {
            i += 1;
        }
    }
    for(int i = cnt; i < k; i++)
        cout << 0 << endl;

}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int num[100005];
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    help(num, n, k);
}
