#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int pre[maxn];
int hobbies[maxn] = {0}; // hobbies的编号也是从1开始
int isRoot[maxn] = {0};

int Find(int x) // 找到x的大boss,并把x的上级全都直接接入大boss直接管理
{
	int r = x; // 暂存
	while(pre[x] != x)
	{
		x = pre[x]; // 不断往上找到x的上级，知道pre[x] = x为止
	}
	// 此时x已经是大boss,只是找到，并未改变原有的结构
	int j;
	// 路径压缩
	while(r != pre[r])
	{
		j = pre[r];
		pre[r] = x; //全都加到大boss直接管理
		r = j;
	}
	return x; // 返回大boss,此时经过路径压缩，结构发生了改变
}

void Union(int a, int b) // 这种做法是让后面的成为大boss
{
	int preA = Find(a);
	int preB = Find(b);
	if(preA != preB)
	{
		pre[preA] = preB; //preB成为大boss
	}
}

void init(int n) // 集合的元素个数
{
	for(int i = 1; i <= n; i++)
	{
		pre[i] = i; // 初始时自己是自己的大boss
		isRoot[i] = 0;
	}
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	scanf("%d", &n);

	init(n); // 初始化的过程很重要

	for(int i = 1; i <= n; i++) // i不仅控制循环，同时也是人的下标
	{
		int k,hobbyIndex;
		scanf("%d:", &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d",&hobbyIndex); // 爱好的标号
			if(hobbies[hobbyIndex] == 0)
			{
				hobbies[hobbyIndex] = i; // i是这个爱好的一个人
			}
			// 已经有人喜欢了，就直接加入即可
			Union(i,Find(hobbies[hobbyIndex]));
		}
	}

	// 数据输入+处理完毕
	for(int i = 1; i <= n; i++)
	{
		isRoot[Find(i)]++; // 计算每个集合的人数
	}

	int ans = 0; // 统计总人数
	for(int i = 1; i <= n; i++)
	{
		if(isRoot[i] != 0)
		{
			ans++;
		}
	}
	sort(isRoot + 1, isRoot + n + 1, cmp);
	printf("%d\n", ans);
	for(int i = 1; i <= ans; i++)
	{
		printf("%d", isRoot[i]);
		if(i < ans)
		{
			printf(" ");
		}
	}

	printf("\n");
	return 0;
}