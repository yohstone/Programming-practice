#include<iostream>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
	
	//方法1 
    int romanToInt(string s) {
        map<char, int> roman;
        int sum = 0, len = s.length();
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        for(int i=0; i<len; i++){
        	if( roman[s[i]] < roman[s[i+1]]){
        		sum = sum - roman[s[i]];
			}else{
				sum = sum + roman[s[i]];
			}
		}
		return sum;
    }
    //方法2  执行效率较高 
    int romanToInt2(string s) {
    	int sum = 0, len = s.length(); 
        for(int i=0; i<len; i++){
        	if( s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X' ) ){
        		sum = sum - 1;
			}else if( s[i] == 'I'){
				sum = sum + 1;
			}else if( s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
				sum = sum - 10;
			}else if( s[i] == 'X'){
				sum = sum + 10;
			}else if( s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
				sum = sum - 100;
			}else if( s[i] == 'C'){
				sum = sum + 100;
			}else if( s[i] == 'V'){
				sum = sum + 5;
			}else if( s[i] == 'L'){
				sum = sum + 50; 
			}else if( s[i] == 'D'){
				sum = sum + 500;
			}else if( s[i] == 'M'){
				sum = sum + 1000;
			}
		}
		return sum;
    }
};
int main(){
	Solution s;
	string str;
	
	while(cin >> str){
		cout << s.romanToInt2(str) << endl;
	}
    
	return 0;
}
