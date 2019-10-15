#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    long long Ai;
    long long maxAi = 0;
    vector<long long> requiresA;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long temp;
        cin >> temp;
        requiresA.push_back(temp);
        if(temp > maxAi){
            maxAi = temp;
        }
    }
    cout << maxAi + 1 << endl;
}

