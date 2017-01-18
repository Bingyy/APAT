#include<stdio.h>
#include<math.h>
//不能处理大数的情况
//A:[1-9]
//N: [0-100000]
//这是很大的数，需要用字符串的方式进行计算

int main(){
	int A, N;
	scanf("%d%d",&A, &N);
	int sum = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < i; j++){
			sum += pow(10,j);
		}
	}
	printf("%d\n", sum * A); ;
}