#include<iostream>
#include<vector>
using namespace std;
long long sum = 0;
long long res = 0;
vector<long long> nums;
void findSeq(long long num, long long N, long long S){
    if(sum + num == S && nums.size() == N){
        res++;
        sum = 0;
        nums.resize(0);
    }else if(sum + num < S && nums.size() < N){
        nums.push_back(num);
        findSeq(num+1, N, S);
    }else{
        nums
        return;
    }

}

int main() {
    long long N, S;
    vector<long long> nums;
    long long sum = 0;
    long long res = 0;
    cin >> N >> S;
    findSeq(1, N, S);
    cout << res << endl;
    return 0;
}
