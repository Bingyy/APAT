
#include <iostream>
#include <string>
#include <map>

using namespace std;
const int maxn = 2010;
const int inf = 100000000;

map<string,int> nameToNumber; //将姓名映射到编号:方便在邻接矩阵算法中处理
map<int,string> numberToString; //方便输出
map<string, int> Gang; // 头目的名字映射到数目

int G[maxn][maxn] = {0}; // 邻接矩阵是全局变量
int weight[maxn] = {0}; // 记录点的权值
bool visited[maxn] = {false};

int n,k,numberPerson = 0; //n是边的数目，k是下限值，numberPerson是总人数，也用于编号


// 本题的重点逻辑编写
//单块遍历
void DFS(int u, int &head, int &numMember, int &totalValue)
{
	numMember++;
	visited[u] = true;
	if(weight[u] > weight[head])
	{
		head = u;
	}
	// 输入结束后，numberPerson就计算出来了
	for(int i = 0; i < numberPerson; i++)
	{
		if(G[u][i] > 0) // 连通
		{
			totalValue += G[u][i];
			G[u][i] = G[i][u] = 0;
			if(visited[i] == false)
			{
				DFS(i,head, numMember,totalValue);
			}
		}
	}
}

// 遍历图
void DFSTraverse()
{
	for(int i = 0; i < numberPerson; i++)
	{
		if(visited[i] == false)
		{
			int head = i, numMember = 0, totalValue = 0;
			DFS(i,head,numMember,totalValue);
			if(numMember > 2 && totalValue > k)
			{
				Gang[numberToString[head]] = numMember;
			}
		}
		
	}
	
}

int changeToNumber(string name)
{
	// 如果已经出现过，那么直接查表拿出这个人的编号即可：在邻接矩阵的表达方式下，编号很重要
	if(nameToNumber.find(name) != nameToNumber.end())
	{
		return nameToNumber[name];
	}
	else // 还没写在映射中，因此分配编号
	{
		//用空间换取时间，姓名和编号做双向映射
		nameToNumber[name] = numberPerson;
		numberToString[numberPerson] = name; 
		return numberPerson++; // 返回的是当前编号，并在返回后使得编号自增，这个以前没太在意
	}
}

int main()
{	
	int time;
	string name1, name2;
	cin >> n >> k;
	for(int i = 0; i < n;i++)
	{
		cin >> name1 >>name2 >> time; //输入格式：AAA BBB 10
		//先写入映射
		int id1 = changeToNumber(name1);
		int id2 = changeToNumber(name2);
		// 输入时就处理点的权值
		weight[id1] += time;
		weight[id2] += time;
		// 处理边的权值
		G[id1][id2] += time;
		G[id2][id1] += time;
	}

	// 以上就是图的模型建立

	// 处理放在DFS中进行
	DFSTraverse();
	cout << Gang.size() << endl;
	for(auto it = Gang.begin(); it != Gang.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}