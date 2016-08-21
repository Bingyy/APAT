#include<stdio.h>

int main(){
	int a;
	int b;
	while(scanf("%d%d\n",&a,&b) != EOF){
		int sum = 0;
		char result[20];
		sum = a + b;

		if(sum < 0){
			printf("-");
			sum = -sum;
		}
		else if(sum == 0){
			printf("0");
		}

		int count = 1,tmp;
		while(sum > 0){
			tmp = sum % 10;
			sum = sum / 10;
			result[count++] = tmp + '0';
			if(sum != 0 && count % 4 == 0){
				result[count++] = ',';
			}
		}

		count--;

		for(int i = count; i >= 1; i--){
			printf("%c", result[i]);
		}
	}
	return 0;
}