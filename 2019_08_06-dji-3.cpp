#include<iostream>

using namespace std;


int divide(int V, int N, int c_i[], int M, int pri[]){
	int c_num[200] = {0};
	int num = 0;
	int sum = 0;
	int low = 0;
	int tempPrice = 0;
	int index = 0;
	int highprice = 0;
	int i = 0;
	int roundSum = 0;
	int nonpri[200] = {0};
	int j = 0;
	for (i = 0; i < M; i++){
		c_num[pri[i] - 1] = M - i;
		tempPrice += c_i[pri[i] - 1] * c_num[pri[i] - 1];
	}
	highprice = tempPrice;
	if (highprice == V){
		cout<<++num<<endl;
		return 0;
	}
	int nValue = 0;
	for (i = 0; i < N; i++){
		int flag = 0;
		for (j = 0; j < M; j++){
			if (i+1 == pri[j]){
				flag = 1;
				break;
			}
		}
		if (flag==0){
			nonpri[nValue] = i+1;
			nValue++;
		}
	}
	c_num[pri[0] - 1] = V % c_i[pri[0] - 1];
	sum += c_num[pri[0] - 1] * c_i[pri[0] - 1];
	index++;
	while (sum <= V){
		if (sum == V){
			num++;
		}
		sum += c_i[pri[index] - 1];
		c_num[pri[index] - 1]++;
		if (sum > V){
			if (c_num[pri[index]] + 1 == c_num[pri[index - 1]]){
				sum = sum - c_i[pri[index] - 1];
				c_i[pri[index]]--;
			}else{
				if (index < M - 1){
					index++;
				} else {
					low = c_i[pri[M-1] - 1] - 1;
					if (low == -1){
						break;
					}
					int comIndex = 0;
				        while (sum <= V){
			                	if (sum == V){
                        				num++;
                				}
                				if (c_num[nonpri[comIndex] - 1] + 1 == low){
                					comIndex++;
                				} else {
                					sum += c_i[nonpri[comIndex] - 1];
                					c_num[nonpri[comIndex] - 1]++;
                				}
                				if (sum > V){
                                	sum = sum - c_i[nonpri[comIndex] - 1];
                					c_num[nonpri[comIndex] - 1]--;
                				}
        				}
				}
			}
		}
	}
	cout<<(num%10000007)<<endl;
	return 0;
}


int main(){
	int V = 0, N = 0;
	int c_i[200] = {0};
	int M;
	int pri[200] = {0};
	cin>>V>>N;
	for (int i = 0; i < N; i++){
		cin>>c_i[i];
	}
	cin>>M;
	for (int i = 0; i < M; i++){
		cin>>pri[i];
	}
	divide(V, N, c_i, M, pri);
	return 0;
}
