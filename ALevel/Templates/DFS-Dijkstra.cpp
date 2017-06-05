#include <vector>
// 2017-2-21
// 本题适合用a1030来作为训练

int optValue;// 第二标尺最优值
vector<int> pre[MAXV];
vector<int> path, tempPath;

void DFS(int v) // v是当前访问结点
{
	// 递归边界
	if(v == st) //st是路径起点，也是叶子结点
	{
		tempPath.push_back(v);//加入临时路径
		int value;//存放临时路径tempPath的第二标尺值
		// 计算路径tempPath上的value值
		if(value优于optValue)
		{
			optValue = value;
			path = tempPath;
		}

		tempPath.pop_back();//将刚加入的结点删除
		return;
	}

	// 递归式
	tempPath.push_back(v);//将当前访问的结点加入临时路径tempPath的最后面
	for(int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]); //pre[v][i]是结点v的前驱
	}
	tempPath.pop_back();// 遍历完所有前驱结点，将当前结点v删除
}