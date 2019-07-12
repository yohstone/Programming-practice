#include<stdio.h>
#include<math.h>

// 计算小于n的质数总数
int countPrimes(int n) {
    int count = 1;
    if(n <= 2){
        return 0;
    }
    // 为了提高效率，减少计算次数，从3开始，每次循环后+2
    for(int i = 3; i < n; i += 2){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}

// 判断x是否是质数
bool isPrime(int x){
    if(x == 2){
        return true;
    }
    if(x % 2 == 0){
        return false;
    }
    // 为了提高效率，减少计算次数，从3开始，每次循环后+2
    for(int j = 3; j <= sqrt(x); j += 2){
        if(x % j == 0){
            return false;
        }
    }
    return true;
}
// 厄拉多塞筛选法：先将2 至 n 范围内的数放到表中，然后给2打上标记，依次划去2的倍数、然后下一个未被标记也未被划去的是3，继续划去3的倍数、
// 依次类推，直到范围内的所有数都被划去或被标记了，被标记的就是质数，实现2
int countPrimes2(int n){
    vector<bool> num(n, true);
    int count = 0;
    for(int i = 2; i < n; i++){
        if(num[i]){
            count++;
            for(int j = 2; i*j < n; j++){
                num[j*i] = false;
            }
        }
    }
    return count;
}
int main(){
	int n;
	int flag = 0; //true:1
	while(scanf("%d", &n)){

		if(isPrime(n)){
			printf("%d is prime number\n", n);
		}else{
			printf("not a prime\n");
		}
	}
	return 0;
}
