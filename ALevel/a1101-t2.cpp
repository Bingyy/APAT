#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 1 << 30;
int ins[maxn] = {0};
int res[maxn]; // 记录主元
int num = 0;
int leftMax[maxn], rightMin[maxn]; 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &ins[i]);
	}

	leftMax[0] = 0; // 初始化， leftMax[i]:表示0 ~ i - 1 的最大值
	for(int i = 1; i < n; i++)
	{
		// if(ins[i - 1] > leftMax[i - 1]) // 从左往右扫描，大小的继承关系
		// {
		// 	leftMax[i] = ins[i - 1]; // 更新当前的最大值是ins[i]
		// }
		// else
		// {
		// 	leftMax[i]= leftMax[i - 1];
		// }
		leftMax[i] = max(ins[i - 1], leftMax[i - 1]); // 注释掉的等同于这一句,调用这个函数比自己实现的快。。
	}

	rightMin[n - 1] = INF;

	for(int i = n - 2; i >= 0; i--)
	{
		// if(ins[i + 1] < rightMin[i + 1]) // 从右往左扫描
		// {
		// 	rightMin[i] = ins[i + 1];
		// }
		// else
		// {
		// 	rightMin[i] = rightMin[i + 1];
		// }
		rightMin[i] = min(ins[i + 1], rightMin[i + 1]);
	}

	for(int i = 0;i < n; i++)
	{
		if(leftMax[i] < ins[i] && rightMin[i] > ins[i])
		{
			res[num++] = ins[i];
		}
	}

	// 控制输出

	printf("%d\n",num);

	for(int i = 0; i < num; i++)
	{
		printf("%d", res[i]);
		if(i < num - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}