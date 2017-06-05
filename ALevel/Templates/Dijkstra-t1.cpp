#include <vector>

using namespace std;

const int MAXN = 1000;
const int INF = 1 << 30

int n; // 顶点数：输入决定
int d[MAXN] = {INF};
int G[MAXN][MAXN] = {INF}; // 邻接矩阵，由用户输入构建
bool visited[MAXN] = {false};
// 邻接矩阵版本
void Dijkstra_Matrix(int s) //起点
{
	// 初始化
	fill(d,d+MAXN,INF);
	d[s] = 0;
	// 找到使得d[u]最小的且未被访问的顶点标号
	for(int i = 0; i < n; i++) // 外层控制循环n次，选择n次最小的距离，起始点也是在这循环下面选择的
	{
		int u = -1, MIN = INF; //需要下标+最小值
		for(int j = 0; j < n;j++)
		{
			if(visited[j] == false && d[j] < MIN) // 未访问的+距离起点最小的
			{
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return; //没有找到，表示顶点可达的用完了，直接返回，结束此函数
		// 标记u已经访问
		visited[u] = true; 
		// 更新所有未访问过的集合V-S中且可到达顶点的最近距离，因为这没法直接锁定，所以还是再来一次循环，在判断语句中筛选
		//这个算法新加入的不会反过来影响已经加入访问过的集合S中的顶点的距离
		for(int v = 0; v < n; j++)
		{
			// 以u作为中介，如果距离更小了，往前更新v的距离：优化距离
			if(visited[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
			{
				d[v] = d[u] + G[u][v];
			}
		}	
	}
}


// 邻接表版：用vector<node> Adj[MAXN]来表述
int d[MAXN] = {INF}; // 初始化所有的顶点全部为不可达
bool visited[MAXN] = {false};

struct node
{
	int v,dis; // v是顶点编号，dis是距离起点距离
};
vector<node> Adj[MAXN];
void Dijkstra_Adj(int s)
{
	// 初始化
	// 找寻V-S中最小距离顶点编号
	fill(d,d+MAXN,INF); //全部初始化为不可达
	d[s] = 0;// 确定s是起始点，则也初始化一下

	// 也是在未访问的+起点可达的顶点中选择
	for(int i = 0; i < n; i++) // 控制循环n次，表示选择n次最小距离顶点下标u
	{
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++)
		{
			if(visited[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}

		if(u == -1) return;

		visited[u] = true;
		// 这里的u已经找到,更新u加入后的其他未加入的距离
		for(int j = 0; j < Adj[u].size(); j++) // 直接在邻接表中寻找
		{	
			int v = Adj[u][j].v; //注意v是顶点在顶点表中编号，j是邻接表中的顶点下标
			if(visited[v] == false && d[u] + Adj[u][j].dis < d[v])
			{
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}

}





