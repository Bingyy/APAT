#include<iostream>
using namespace std;

int pre[1050];
#define bool int

bool t[1050];//用于标记独立块的根节点 -- 标记谁是掌门

int find(int x)
{
	int r = x;
	while(r != pre[r])//直到自己是自己的老大为止
		r = pre[r];
	//路径压缩
	int i = x, j;
	while(r != pre[i]) //如果i的老大不是掌门人
	{
		j = pre[i]; //暂时存储一下i的老大
		pre[i] = r; //更改i的老大为直接掌门人
		i = j; //再去搞i的曾经的老大
	}
	return r;
}

void join(int x, int y)//让x和y做朋友
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		pre[fy] = fx;
}

int main()
{
	int N,M,a,b,i,j,ans;//N表示结点数，M表示连通的边数
	while(scanf("%d%d",&N,&M) &&N) //如果读入的N为0结束
 	{
		for(i = 1; i <= N; i++)//初始化，每个人是自己的老大
			pre[i] = i;
		for(i = 1; i <= M; i++)
		{
			//吸收并整理数据
			scanf("%d%d",&a,&b);
			join(a,b);
		}

		memset(t,0,sizeof(t));
		// for(i = 1; i <= N; i++)
		// {
		// 	//标记根结点
		// 	t[find(i)] = 1;
		// }
		// for(ans = 0,i=1; i<=N; i++)
		// {
		// 	if(t[i])
		// 		ans++;
		// }
	//注释的代码等同于下面的一个循环，且少了一个1050个元素的数组
		for(ans = 0,i=1; i<=N; i++)
		{
			if(pre[i] == i)
				ans++;
		}

		printf("%d\n",ans - 1);
	}
	return 0;
}