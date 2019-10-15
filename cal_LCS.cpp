#include<iostream>
#include<vector>
#include<string>
using namespace std;

string calLCS(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> distance(n+1, vector<int> (m+1, 0));
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str[j-1]){
                distance[i][j]
            }
        }
    }
}

int main(){

}
