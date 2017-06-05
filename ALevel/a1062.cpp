#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int cnt = 0; //记录能上榜的人

struct node
{
	char id[10];
	int de;
	int cai;
	int clarity;
}T[100010]; //结构体数组

bool cmp(node a, node b) // 这种比较函数的写法很具有代表意义，按照多个因素排序，权重大的因素排在前！
{
	if(a.clarity != b.clarity) 
	{
		return a.clarity < b.clarity; //按照级别递增排序，级别小的是更好的
	}
	else if(a.de + a.cai != b.de + b.cai) // 级别相同时，按照总分大的排前面
	{
		return a.de + a.cai > b.de + b.cai;//按照总分递减排序
	}
	else if(a.de != b.de) // 总分相同时，按照德分大的在前
	{
		return a.de > b.de;
	}
	else
	{
		return strcmp(a.id,b.id) < 0; //德分相同时，按照id小的在前：此处，级别相同，总分相同，德分相同
	}
}

int main()
{
	int n,l,h; //学生数，下限，上限
	scanf("%d%d%d",&n,&l,&h);
	// 处理输入数据
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d%d",T[i].id, &T[i].de,&T[i].cai);
		if(T[i].de >= l && T[i].cai >= l)
		{
			// 计算几个人数
			cnt++; //输入时处理数据，在算法题中，输入数据时是暴露数据的窗口，也是处理数据的极佳时机
		}
		
		// 处理类别，类别作为一个比较因素，需要写入
		// 第五类先处理掉，下面的判断语句可以简化：不用再另加是否大于l
		if(T[i].de < l || T[i].cai < l) // 只要任何一项低于l线，那么就是第五类
		{
			T[i].clarity = 5;
		}
		else if(T[i].de >= h && T[i].cai >= h)
		{
			T[i].clarity = 1;// 级别1最好:sages
		}
		else if(T[i].de >= h && T[i].cai < h)
		{
			T[i].clarity = 2;// 级别2次好：noblemen
		}
		else if(T[i].de >= T[i].cai)
		{
			T[i].clarity = 3; //虽不及君子，但德高于才：fool men
		}
		else
		{
			T[i].clarity = 4; // 小人
		}
	}
	// 排序
	sort(T,T+n,cmp);

	printf("%d\n",cnt);

	for(int i = 0; i < cnt; i++)
	{
		printf("%s %d %d\n", T[i].id, T[i].de, T[i].cai);
	}
	
	return 0;
}