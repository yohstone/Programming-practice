#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
    int N, M;
    while(cin >> N >> M) {
        map<string, string> order;
        while(N--){
            string cmd, action;
            cin >> cmd >> action;
            order[cmd] = action;
        }
        while(M--){
            string cmd2;
            cin >> cmd2;
            cout << order[cmd2] << endl;
        }
    }
    return 0;
}
