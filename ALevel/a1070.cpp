#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 2017-2-24
// 贪心思路学习
//  Mooncake: 按照最贵的先卖即可

// 全以double定义数据，否则会有一个边界数据通不过去

const int MAXN = 1010;
struct node
{
	double weight;
	double val;
	double rate;
} kinds[MAXN];

bool cmp(node a, node b)
{
	return a.rate > b.rate; // 按照价格/重量递减排序
}

int main(int argc, char const *argv[])
{
	int n;// n:kinds, d:demands

	double d;
	double totalProfit = 0.0;

	scanf("%d%lf",&n,&d);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf",&kinds[i].weight);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%lf",&kinds[i].val);
		kinds[i].rate =(double)(kinds[i].val / kinds[i].weight);
	}

	sort(kinds,kinds + n,cmp);

	// 处理购买流程
	for(int i = 0; i < n; i++) // kinds已经按照性价比排好序了，优先买前面的
	{

		if(d >= kinds[i].weight)
		{
			d -= kinds[i].weight;
			totalProfit += kinds[i].val;
		}
		else 
		{
			totalProfit += (d / kinds[i].weight) * kinds[i].val;
			break; // 如果库存量大于剩余需求量要中断此循环
		}
	}
	
	printf("%.2f\n", totalProfit);

	return 0;
}