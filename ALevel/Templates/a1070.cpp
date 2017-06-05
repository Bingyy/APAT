#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 2017-2-24
// 贪心思路学习
//  Mooncake: 按照最贵的先卖即可

const int MAXN = 1010;
struct node
{
	int weight;
	double val;
	double rate;
} kinds[MAXN];

bool cmp(node a, node b)
{
	return a.rate > b.rate; // 按照价格/重量递减排序
}

int main(int argc, char const *argv[])
{
	int n, d;// n:kinds, d:demands
	double totalProfit = 0.0;

	scanf("%d%d",&n,&d);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&kinds[i].weight);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&kinds[i].val);
		kinds[i].rate = kinds[i].val / kinds[i].weight;
	}

	sort(kinds,kinds + n);

	// 处理购买流程
	for(int i = 0; i < n; i++)
	{
		if(d >= kinds[i].weight)
		{
			d -= kinds[i].weight;
			totalProfit += kinds[i].val;
		}
		else
		{
			totalProfit += (d / kinds[i].weight) * kinds[i].val;
			break;
		}
	}
	
	printf("%.2f\n", totalProfit);

	return 0;
}