#include<iostream>
#include<string>
using namespace std;



/**
 * 网易2020校园招聘模拟笔试 - 2
 * 将4个及4个以上连续字典序的字母转为"首个字母-结束字母"的形式
 * 思路：
 * 从输入字符串的第一个字母开始遍历到其倒数第2个字母，判断 str[i] + 1 是否等于 str[i + 1]，若是则暂存字母序列到 sub_str 中
 * 当时 str[i] + 1 != str[i + 1] 时, 若 sub_str.size() >= 3，则可以拼接出"首个字母-结束字母"的形式，若count < 3，则还是以原来的序列添加到结果字符串中
 */

// 压缩字符串函数，返回缩写后的字符串
string compressString(string str){
    int len = str.size();
    if(len < 4){
        return str;
    }
    string res = "";        // 返回结果
    string sub_str = "";    // 用于暂存子串
    int i = 0;
    for(; i < len - 1; i++){
        if(str[i] + 1 == str[i + 1]){
            sub_str += str[i];
        }else{
            if(sub_str.size() >= 3){
                res = res + sub_str[0] +  "-" + str[i];
            }else{
                res = res + sub_str + str[i];
            }
            sub_str = "";   // 初始化
        }
    }

    if(sub_str.size() >= 3 && str[i - 1] + 1 == str[i]){  // 因为 str[len - 1] 尚未遍历，所以还需再判断一次
        res = res + sub_str[0] + "-" + str[i];
    }else{
        res = res + sub_str + str[i];
    }
    return res;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        cout << compressString(s) << endl;
    }
	return 0;
}



// 旧代码，写得有些乱。 样例过了，但是只AC 20%
//#include<iostream>
//#include<string>
//#include<cmath>
//
//using namespace std;
//
//string zipString(string str){
//    int len = str.size();
//    if(len < 4){
//        return str;
//    }
//    string res = "";
//    char pre_char = str[0];
//    int flag = 0;           // 用于标志 "-" 是否已添加到 res 中
//    string sub_str1 = "";   // 缩写后的子串
//    string sub_str2 = "";   // 未缩写的子串
//    for(int i = 0; i < len; i++){
//        if(i > 0 && str[i] == pre_char + 1){
//            sub_str2 += str[i];     // 先放入子串2z中
//            if(flag == 0){
//                sub_str1 += "-";
//                flag = 1;
//            }else if(flag == 1 && ( str[i]+1 != str[i+1] || i == len - 1 )){  // 到缩写的结尾了
//                sub_str1 += str[i];
//                if(sub_str2.size() >= 3){         // 长度满足要求才放入res
//                    res += sub_str1;
//                }else{
//                    res += sub_str2;
//                }
//                flag = 0;       // 初始化
//                sub_str1 = "";  // 初始化
//                sub_str2 = "";
//            }else{              // 未到缩写结尾
//            }
//        }else{
//            if(sub_str2.size() >= 1){
//                res += sub_str2;
//                sub_str2 = "";
//                i--;
//            }else{
//                res += str[i];
//            }
//        }
//        pre_char = str[i];
//    }
//    return res;
//}
//
//
//int main(){
//    int T;
//    cin >> T;
//    while(T--){
//        string s;
//        cin >> s;
//        cout << zipString(s) << endl;
//    }
//	return 0;
//}
