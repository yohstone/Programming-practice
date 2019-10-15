#include<iostream>
#include<map>
#include<cmath>
using namespace std;



class test{};
#define f(x) x*x

int main(){

    int i = 1;
    int j = sizeof(i++);
    test t;
    cout << i << " "<< j << endl;
    cout << sizeof(test) << endl;
    cout << sizeof(t) << endl;
    int x = f( 4 + 4) / (2 + 2);
    cout << x << endl;
	return 0;
}





