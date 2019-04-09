#include<iostream>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman;
        map<int, string>::reverse_iterator iter;
        int times;
        string r = "";
        
        roman[1]  = "I";
        roman[4]  = "IV";
        roman[5]  = "V";
        roman[9]  = "IX";
        roman[10] = "X";
        roman[40] = "XL";
        roman[50] = "L";
        roman[90] = "XC";
        roman[100]  = "C";
        roman[400]  = "CD";
        roman[500]  = "D";
        roman[900]  = "CM";
        roman[1000] = "M";
        while(num){
        	for(iter = roman.rbegin(); iter != roman.rend(); iter++){
        		//cout << iter->first  << ' ' << iter->second << endl;
        		if(num >= iter->first ){
//        			cout << "r = " << r << "  num = " << num << endl; 
//        			cout << "first = " << iter->first << "  second = " << iter->second << endl; 
					times = num / iter->first;
					while(times--){
						r.append( iter->second );
						num -= iter->first;
					}
				}
			}
		}
        return r;
    }
};
int main(){
	Solution s;
	int num;
	while(cin >> num){
		cout << s.intToRoman(num) << endl;
	}
	
	return 0;
}
