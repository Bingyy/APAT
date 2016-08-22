///Author:王兵
///Time: 2016-8-22 17:25
///得分： 14/15 --边界在哪个没处理到？？

#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
				
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */

int Count_Digit(const int N, const int D){
	int n = N;
	if(N < 0){
		n = -N;
	}
	//还是用桶的方法收集数据
	int container[10];
	for(int i = 0; i < 10; i++){
		container[i] = 0; //initial
	}
	while(n != 0){
		container[n % 10]++;
		n /= 10;
	}

	return container[D];

}