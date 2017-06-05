#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

const int maxn = 100010;
struct node
{
	double data;// 出货量：只有叶子结点才会真的面向消费者
	vector<int> child; // 存储子结点的下标
} Node[maxn];

double p,r,ans = 0;

int n;

void DFS(int index, int depth) // index是结点下标
{
	if(Node[index].child.size() == 0) // 递归边界：叶结点
	{
		ans += Node[index].data * pow(1 + r,depth); //
		return ;// 返回
	}

	for(int i = 0; i < Node[index].child.size(); i++)
	{
		DFS(Node[index].child[i], depth + 1); // 递归访问结点index的所有子结点
	}
}


// 以上这样一番DFS下来，就可以计算出来maxDepth 和 num

int main(int argc, char const *argv[])
{
	int k, child;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100; //输入时给的是百分比数字

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		if(k == 0)
		{
			scanf("%lf",&Node[i].data); // 输入出货量
		}
		else
		{
			for(int j = 0; j < k; j++)
			{
				scanf("%d",&child);
				Node[i].child.push_back(child);// 存储结点i的子结点
			}
		}
	}
	DFS(0,0); // 入口
	printf("%.1f\n",p * ans);
	return 0;
}