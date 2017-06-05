/*
1094. The Largest Generation (25)
A family hierarchy is usually presented by a pedigree tree 
where all the nodes on the same level belong to the same 
generation. 
Your task is to find the generation with the largest population.

Input Specification:

Each input file contains one test case. Each case starts with 
two positive integers N (<100) which is the total number of 
family members in the tree (and hence assume that all the members 
are numbered from 01 to N), and M (<N) which is the number of 
family members who have children. Then M lines follow, each contains 
the information of a family member in the following format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a family member, K (>0) 
is the number of his/her children, followed by a sequence of two-digit 
ID's of his/her children. For the sake of simplicity, let us fix the 
root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the largest population number 
and the level of the corresponding generation. It is assumed that 
such a generation is unique, and the root level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
*/

#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 110;

vector<int> Node[maxn];

int hashTable[maxn];// 记录每一层的结点数

// DFS的目的就是为了计算hashTable
void DFS(int index, int level) // 如果用DFS需要用到两个参数：结点编号，层号
{
	// 这个似乎没有递归边界，那么只有等函数用完自然结束
	hashTable[level]++; // 进来本层结点数就自增
	for(int j = 0; j < Node[index].size();j++) // 处理递归式，这也是个循环处理
	{
		DFS(Node[index][j],level + 1); // 孩子结点的编号，层数
	}
}

int main()
{
	int n,m, parent, k, child; // 这里的n没什么用啊
	scanf("%d%d",&n, &m);
	for(int i = 0; i < m; i++) // 控制循环次数
	{
		scanf("%d%d", &parent, &k);
		for(int j = 0; j < k; j++) // 控制循环次数
		{
			scanf("%d", &child);
			Node[parent].push_back(child); // 建树
		}
	}

	DFS(1,1); // 根结点编号为1，层号为1
	// 只用找到最大的值，所以不用排序
	int maxLevel = -1, maxValue = 0;
	for(int i = 1; i < maxn; i++) // 层数从1开始计算
	{
		if(hashTable[i] > maxValue)
		{
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}

	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}
