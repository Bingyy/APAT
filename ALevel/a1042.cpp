#include <stdio.h>

const int N = 54;
char mp[5] = {'S','H','C','D','J'};
int start[N+1],end[N+1],next[N+1];

int main()
{
	int K;
	scanf("%d",&K);// 洗牌次数
	for(int i = 1; i <= N; i++)
	{
		start[i] = i; // 初始牌号
	}

	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &next[i]); // 存储输入的牌号,也即翻牌的规则
	}

	for(int step = 0; step < K; step++)
	{
		for(int i = 1; i <= N; i++)
		{
			end[next[i]] = start[i]; // 第i个位置的牌存于next[i]
		}
		for(int i = 1; i <= N; i++)
		{
			start[i] = end[i]; // 把end数组内容赋予start，用于下次再shuffle
		}
	}
	// 控制输出,start[i]存储的是x
	for(int i = 1; i <= N; i++)
	{
		printf("%c%d",mp[(start[i] - 1)/13],(start[i]-1) % 13 +1);
		if(i != N) printf(" ");
	}
	printf("\n");
	return 0;
}