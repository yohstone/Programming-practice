#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    string tolowerCase(string str){
        for(int i=0; i<str.length(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + 32;
            }
        }
        return str;
    }
};

int main(){
    Solution s;
    cout << s.tolowerCase( "HHHHHeellpo");
    return 0;
}
