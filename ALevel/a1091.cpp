#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
	int x, y, z; // 位置(x,y,z)
} Node;

int n, m, slice, T; // 矩阵是n*m， 共slice层， T是核心区中1的下界

int pixel[1290][130][61]; // 三维01矩阵
bool inq[1290][130][61] = {false}; // 记录位置是否入队

int arrX[6] = {0,0,0,0,1,-1};
int arrY[6] = {0,0,1,-1,0,0};
int arrZ[6] = {1,-1,0,0,0,0};

bool judge(int x, int y, int z)
{
	if(x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0)
	{
		return false; //越界则返回false
	}
	if(pixel[x][y][z] == 0 || inq[x][y][z] == true)
	{
		return false; // 当前位置为0或者已经入过队则返回false
	}
	// 否则就返回true
	return true;
}

// BFS访问位置(x,y,z)所有的块，将该块中所有的1的inq设置为true
int BFS(int x, int y, int z)
{
	int total = 0; // 计数当前块中1的个数
	queue<node> q; // 定义队列
	Node.x = x,Node.y = y, Node.z = z;
	q.push(Node);
	inq[x][y][z] = true;
	while(!q.empty())
	{
		node top = q.front();
		q.pop();
		total++;
		for(int i = 0; i < 6; i++)
		{
			int newX = top.x + arrX[i];
			int newY = top.y + arrY[i];
			int newZ = top.z + arrZ[i];
			if(judge(newX, newY, newZ))
			{
				Node.x = newX, Node.y = newY, Node.z = newZ;
				q.push(Node);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if(total >= T)
	{
		return total;
	}
	else
	{
		return 0;
	}
} 

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d", &n, &m, &slice, &T);
	for(int z = 0; z < slice; z++)
	{
		for(int x = 0; x < n; x++)
		{
			for(int y = 0; y < m; y++)
			{
				scanf("%d", &pixel[x][y][z]);
			}
		}
	}

	int ans = 0;
	for(int z = 0; z < slice; z++)
	{
		for(int x = 0; x < n; x++)
		{
			for(int y = 0; y < m; y++)
			{
				if(pixel[x][y][z] == 1 &&inq[x][y][z] == false)
				{
					ans += BFS(x,y,z);
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}




