#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int flag = 0; //true:1
	while(scanf("%d", &n)){

		for(int i=2; i<n; i++){//sqrt(n)
			if(n % i == 0){
				flag = 0;
				break;
			}else{
				flag = 1;
			}
		}
		if(flag){
			printf("%d is prime number\n", n);
		}else{
			printf("false\n");
		}
	}
	return 0;
}
