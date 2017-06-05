#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1010;
// 并查集
int pre[maxn];
int isRoot[maxn] = {0};
int hobbies[maxn] = {0};

int find(int x) // 寻找x所在的集合的大boss
{
	int temp = x;
	while(x != pre[x])
	{
		// x不是自己的boss
		x = pre[x]; // 逐级向上，x的值变了，所以为了路径压缩需要在开始暂存
	}

	// 路径压缩：把找x的boss的过程中遇到的全都设置为大boss
	while(temp != pre[temp])
	{
		int j = temp; 
		temp = pre[temp]; // 往上层走,为下一层循环做铺垫
		pre[j] = x; 
	}
	return x;
}

void join(int x, int y)
{
	int preX = find(x);
	int preY = find(y);
	if(preX != preY)
	{
		pre[preX] = preY; // preX的大boss现在是preY了
	}
}

void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		pre[i] = i;
		isRoot[i] = 0;
	}
}

bool cmp(int a, int b)
{
	return a > b;
}

// 上面模板准备好以后就可以写具体的题目了
// 并查集的题目需要结合着一些标记数组来运行
int main()
{
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i = 1; i <= n; i++) // 人从1~n进行编号
	{
		scanf("%d:", &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &h);
			if(hobbies[h] == 0) // 爱好只是一种关系纽带，基于这个纽带将人聚集在一起
			{
				hobbies[h] = i; // 标记喜欢这个hobby的人的编号
			}
			join(i,find(hobbies[h]));
		}
	}

	for(int i = 1; i <= n; i++)
	{
		isRoot[find(i)]++;
	}

	int ans = 0;
	for(int i = 1; i <= n;i++)
	{
		if(isRoot[i] != 0)
		{
			ans++;
		}
	}

	printf("%d\n",ans);

	sort(isRoot + 1, isRoot + n + 1, cmp);
	for(int i = 1; i <= ans; i++)
	{
		printf("%d", isRoot[i]);
		if(i < ans)
		{
			printf(" ");
		}
	}

	printf("\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", pre[i]);
	}

	printf("\n");
	for(int i = )
	return 0;
}