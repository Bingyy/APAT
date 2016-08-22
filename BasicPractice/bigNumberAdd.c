//大数加法
#define M 1000
#include<stdio.h>
#include<string.h>

void Add(char s1[], char s2[]){
	int num1[M],num2[M];
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	//num[0]保存的是低位
	for(int i = len1 - 1, j = 0; i >= 0;i--){
		num1[j++] = s1[i] - '0';
	}
	for(int i = len2 - 1,j = 0; i >= 0; i--){
		num2[j++] = s2[i] - '0';
	}
	for(int i = 0; i < M; i++){
		num1[i] += num2[i];//每一位相加，再处理进位
		if(num1[i] > 9){
			num1[i] -= 10;
			num1[i+1]++;
		}
	}

	//打印结果
	for(int i = M; i >= 0 && num1[i] == 0; i--){
		if(i>=0){
			for(;i >= 0; i--){
				printf("%d", num1[i]);
			}
		}
		else
			printf("0\n");
	}
}
int main(){
	char s1[M],s2[M];
	scanf("%s %s",s1,s2);
	Add(s1,s2);
	return 0;
}