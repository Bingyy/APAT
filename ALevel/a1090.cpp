#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

const int maxn = 100010;

vector<int> child[maxn]; // 存放树,这种做法就是邻接表存储图的思路

double p,r;

int n, maxDepth = 0, num = 0;// num是最大深度结点个数

void DFS(int index, int depth) // index是结点下标
{
	// 递归写法不是必须要写递归边界，函数本身执行完结束就是一个边界，设定递归边界的原因是需要在函数执行完之前结束本次调用
	if(child[index].size() == 0) // 递归边界：叶结点
	{
		if(depth > maxDepth)
		{
			maxDepth = depth; // 如果深度比最大深度大，更新最大深度
			num = 1;// 重置最大深度结点个数为1
		}
		else if(depth == maxDepth)
		{
			num++; // 如果深度与最大深度相同，则这样的叶子结点个数自增
		}
		return ;// 返回
	}
	for(int i = 0; i < child[index].size(); i++)
	{
		DFS(child[index][i], depth + 1); // 递归访问结点index的所有子结点
	}
}


// 以上这样一番DFS下来，就可以计算出来maxDepth 和 num

int main(int argc, char const *argv[])
{
	int father, root;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100; //输入时给的是百分比数字
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &father);
		if(father != -1)
		{
			child[father].push_back(i); // i是father的子结点
		}
		else
		{
			root = i; // 根结点是root
		}
	}
	DFS(root,0);
	printf("%.2f %d\n",p * pow(1 + r, maxDepth), num);
	return 0;
}