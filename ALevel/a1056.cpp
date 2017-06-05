#include <stdio.h>
#include <queue>

using namespace std;

const int maxn = 1010;

struct mouse
{
	int weight;
	int R; // 排名
} mice[maxn];

int main(int argc, char const *argv[])
{
	int np, ng, order;
	queue<int> q; // 定义队列存储老鼠的编号

	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++)
	{
		scanf("%d",&mice[i].weight); //输入老鼠的重量
	}

	for(int i = 0; i < np; i++)
	{
		scanf("%d", &order);
		q.push(order); /// 按顺序把老鼠的编号入队
	}

	int temp = np, group; // temp为当前轮的比赛总老鼠数目，group是组数
	while(q.size() != 1) // 直到队列中只有一只老鼠为止
	{
		if(temp % ng == 0)
		{
			group = temp / ng;
		}
		else 
		{
			group = temp / ng + 1;
		}

		// 枚举每一组，选出该组质量最大的老鼠
		for(int i = 0; i < group; i++)
		{
			int k = q.front(); // k存放该组最大的老鼠的编号
			for(int j = 0; j < ng; j++)
			{
				if(i * ng + j >= temp)
				{
					break; // 最后一组老鼠不足ng，退出循环
				}
				int front = q.front();
				if(mice[front].weight > mice[k].weight)
				{
					k = front;
				}
				mice[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}

	mice[q.front()].R = 1; // 当对垒中只剩下一只老鼠时，它的排名是第一
	// 输出老鼠的信息
	for(int i = 0; i < np; i++)
	{
		printf("%d", mice[i].R);
		if(i < np - 1)
		{
			printf(" "); // 控制输出：no extra space 
		}
	}

	printf("\n");
	return 0;
}