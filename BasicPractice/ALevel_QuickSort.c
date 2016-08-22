#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int n;
int a[100003];
int b[100003];

int main(){


	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		bool flag[100003];
		memset(flag,true,sizeof(flag));//设置数组内容
		int maxNum = a[0];
		for(int i = 0; i < n; i++){
			if(a[i] < maxNum){
				flag[i] = false;
			}
			else{
				maxNum = a[i];
			}
		}

		int minNum = a[n-1];
		for(int i = n-1; i >= 0; i--){
			if(a[i] > minNum){
				flag[i] = false;
			}
			else{
				minNum = a[i];
			}
		}

		int count = 0;
		for(int i = 0; i < n; i++)
		{
			if(flag[i] == true){
				b[count++] = a[i];
			}
		}

		sort(b, b+count);

		printf("%d\n",count);
		for(int i =0; i < count; i++){
			if(i != 0)
				printf(" ");
			printf("%d", b[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}
