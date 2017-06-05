#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

// 2017-2-23:14:15

// 模拟过程类的题目
struct studentInfo
{
	char id[15];
	int score;
	int location_number;
	int local_rank;
} stu[30010];

bool cmp(studentInfo a, studentInfo b)
{
	if(a.score != b.score) return a.score > b.score; // 递减排序
	else return strcmp(a.id, b.id) < 0; // 分数相同则按照id小的在前
}

int main()
{
	int n,k,num = 0; // n:考场数 k:每个考场的人数 num：总人数
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		// 处理输入
		for(int j = 0; j < k; j++)
		{
			scanf("%s %d",stu[num].id, &stu[num].score); //注意以空格隔开
			stu[num].location_number = i;
			num++; 
		}
		// 本考场排序
		sort(stu + num - k, stu + num, cmp);

		// 这种处理排名的思路也是模板了
		// 已经排完序后的第一个就是本考场第一名
		stu[num - k].local_rank = 1;
		for(int j = num - k + 1; j < num; j++)// 本考场剩余考生
		{
			if(stu[j].score == stu[j-1].score) // 同分
			{
				stu[j].local_rank = stu[j-1].local_rank; // 排名相同
			} 
			else
			{
				stu[j].local_rank = j + 1 - (num - k); // num-k是本考场的第一个人的编号，起点
			}
		}
	}

	printf("%d\n", num); //输出总人数
	// 总排序
	sort(stu, stu+num, cmp);
	int r = 1; // 当前考生排名
	for(int i = 0; i <  num; i++)
	{
		if(i > 0 && stu[i].score != stu[i - 1].score)
		{
			r = i + 1;
		}
		printf("%s ",stu[i].id);
		printf("%d %d %d\n",r,stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}