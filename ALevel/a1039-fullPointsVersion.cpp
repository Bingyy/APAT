#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1; // 姓名散列的上界
vector<int> selectCourse[M];

int getID(char name[]) // 已经规定了学号的格式，这也算一个提示：手工hash
{
	int id = 0;
	for(int i = 0; i < 3; i++)
	{
		id = id * 26 + name[i] - 'A';
	}

	id = id * 10 + name[3] - '0';

	return id;
}

int main()
{
	char name[5];
	int n,k;
	scanf("%d%d", &n,&k);
	for(int i = 0; i < k; i++)
	{
		int course, x; // x是选课人数
		scanf("%d%d",&course, &x);
		for(int j = 0; j < x; j++)
		{
			scanf("%s",name); // 输入该课程下选课的学生姓名
			int id = getID(name);
			selectCourse[id].push_back(course); // 等同于name（id）--vector的映射
		}
	}

	// 这是每个学生一个输出，不是统一输出，控制逻辑几乎相同
	for(int i = 0; i < n; i++)
	{
		scanf("%s", name);
		int id = getID(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		printf("%s %d", name, selectCourse[id].size());
		for(int j = 0; j < selectCourse[id].size(); j++)
		{
			printf(" %d", selectCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
}