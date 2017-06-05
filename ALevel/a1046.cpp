#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int dis[MAXN] = {0}; //存储1号结点到各个结点的距离
int betw[MAXN] = {0};

// 在输入时候预处理数据
// 学习这种数据的处理方式
int main()
{
	int n,m;
	int sum = 0;
	int indexA, indexB;

	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&betw[i]); // 输入(i,i+1)之间的距离，betw[n]表示（n,1）之间的距离
		sum += betw[i];
		dis[i] = sum;
	}

	scanf("%d",&m);
	
	for(int i = 0; i < m; i++) //查询m次
	{
		scanf("%d%d",&indexA,&indexB);
		if(indexA > indexB)
		{
			swap(indexA,indexB);
		}
		int temp = dis[indexB - 1] - dis[indexA - 1];
		printf("%d\n", min(temp,sum - temp));
	}	

	return 0;
}