#include <stdio.h>
#include <string.h> 
#include <algorithm>

using namespace std;

// 借助之前德才论那道题的思路，可以将参与排名的和不参与排名的分成两类
struct node
{
	char name[10];
	int age; // (0,200]
	int netWorth; //净资产
} P[100010];

bool cmp(node a, node b)
{
	if(a.netWorth != b.netWorth)
	{
		return a.netWorth > b.netWorth; //按照财富递减排序
	}
	else if(a.age != b.age) //财富相同，看年龄
	{
		return a.age < b.age; //年龄按照递增排序：年轻的往前排
	}
	else  // 财富同，年龄同：按照名字的字典序递增即可
	{	
		return strcmp(a.name, b.name) < 0;
	}
}
int main()
{
	int n, k;// n: 总人数，k:查询人数
	int m,minAge,maxAge; // 输出符合的m个人

	scanf("%d%d",&n, &k);

	for(int i = 0; i < n; i++)
	{
		scanf("%s %d%d",P[i].name, &P[i].age, &P[i].netWorth);
	}

	sort(P,P + n,cmp);

	for(int i = 1; i <= k; i++)// 从1开始计数,k次查询
	{
		scanf("%d%d%d", &m, &minAge,&maxAge);

		printf("Case #%d:\n", i); //输出抬头格式

		int cnt = 0; //统计在区间的人数

		for(int j = 0; j < n && cnt < m;j++)
		{
			// 通过判断语句过滤即可，如果加clarity属性且每次重新排序的话，就会超时
			if(P[j].age >= minAge && P[j].age <= maxAge)
			{
				printf("%s %d %d\n",P[j].name, P[j].age, P[j].netWorth);
				cnt++;
			}	
		}
		if(cnt == 0)
		{
			printf("None\n");
		}
	}
	return 0;
}