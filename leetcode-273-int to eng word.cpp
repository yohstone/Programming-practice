#include<iostream>
#include<string>
using namespace std;

/*
将非负整数转换为其对应的英文表示。可以保证给定输入小于 231 - 1 
输入: 123
输出: "One Hundred Twenty Three"

输入: 1234567
输出: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


输入: 1234567891
输出: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/


class Solution {
public:
    string numberToWords(int num) {
    	string single[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
		string tenToTwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		string tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int digit=0;//记录遍历整个数时的位数 
        int temp, num2 = num;
        
        string words = "";
        while(num){
    		if(digit == 3 && num % 1000 != 0){
    			words = "Thousand " + words;
			}else if(digit == 6){
				if(num2 % 1000000 == 0){
					words = "Million";
				}else if( num % 1000 != 0 ){
					words = "Million " + words;
				}
			}else if( digit == 9){
				if(num2 % 1000000000 == 0){
					words = "Billion";
				}else{
					words = "Billion " + words;
				}
				
			}
			
        	temp = num %1000;//每次取3位 
        	int d=0;//记录遍历3位数时的位数 
        	int n,m;
        	m = temp % 100;//取后两位用于判断 
        	while(temp){
        		//cout << temp << " " << words << " " << n << " digit="<< digit<< " d=" << d << endl;
        		n = temp % 10; //n取每一位数字 
				if(m >=10 && m < 20){ //ten to twenty 
					words = tenToTwenty[n] + " "+ words;
					m = 0;
					d++;
					temp /= 10;
				}else if(d == 1 && n > 0){
					words = tens[n-2] + " " + words;
				}else if(d == 2 && n > 0 ){
					words = "Hundred " + words;
					words = single[n] + " " + words;
				}else if(digit == 0 && n > 0 ){
					words = single[n]  + " " + words;
				}else if(n > 0){
					words = single[n] + " " + words;
				}
        		d++;
        		temp /= 10;
			}
        	num /= 1000;
			if(num > 0){
				digit += 3;
			}	
		} 
		
		if(words.empty()){
			words = "Zero";
		};
		words.erase(words.find_last_not_of(" ") + 1);
		return "\"" + words + "\"";
    }
};
int main(){
	Solution s;
	int n;
	while(cin >> n){
		cout << s.numberToWords(n) << endl;
	}
	
	return 0;
}
