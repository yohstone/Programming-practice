#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


long long max_group = 0;

// 判断队列是否有序
bool isSorted(vector<long long> &nums){
    for(long long j = 0; j < nums.size() - 1; j++){
        if(nums[j] > nums[j+1]){
            return false;
        }
        cout << nums[j]  << " ";
    }
    cout << endl;
    return true;
}

// 寻找 nums 中最大值，并从最大值前面切割，将nums分成两段
void divide(vector<long long> &nums, long long high){
    long long max_index = -1;
    long long max_h = -1;
    for(long long i = high; i >= 0; i--){
        if(nums[i] > max_h || (nums[i] == max_h && max_index < high) ){
            max_h = nums[i];
            max_index = i;
        }
    }
    cout << max_index << " - " << max_h << endl;
    sort(nums.begin()+max_index, nums.begin()+high+1);
    if(isSorted(nums)){

    }
    max_group++;
//    if(isSorted(nums)){     // 省掉递归已经有序的最前面那组
//        if(max_index != 0){ // 若 max_index != 0 说明前面还有一组
//            max_group++;
//        }
//        return;
//    }else if(max_index == 0){
//        return;
//    }
    if(max_index <= 0){
        return;
    }
    divide(nums, max_index - 1);
}

//10
//69079936 236011312 77957850 653604087 443890802 277126428 755625552 768751840 993860213 882053548

int main() {
    long long N, temp;
    vector<long long> stu;
    cin >> N;
    temp = N;
    while(temp--){
        long long Hi;
        cin >> Hi;
        stu.push_back(Hi);
    }

    divide(stu, stu.size()-1);

    if(isSorted(stu))
        cout << max_group << endl;
    else
        cout << 1 << endl;

    return 0;
}

//// 方法2
int maxChunksToSorted(vector<int>& arr) {
    stack<int> s;
    for(auto x : arr) {
        if(s.empty() || x >= s.top()) {
            s.push(x);
        } else {
            auto top = s.top();  // 保留栈顶最大值
            s.pop();
            while(!s.empty() && x < s.top()) {  // 若小于则一直pop
                s.pop();
            }
            s.push(top);
        }
    }
    return s.size();
}
