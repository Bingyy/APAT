#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1010;


// 仍是排序问题
struct node
{
	char name[30]; // 姓名
	int month, day,hour, minute; // 打电话日期，时间：月:日:时:分
	bool status; // false: off-line , true : on-line
} rec[MAXN],temp; // 记录统计：结构体数组,temp用于辅助输入

int rates[24]; //24小时的费率数据，rates[0]:00:00 ~ 01:00的费率

// 比较函数，综合考量多个维度的因素
// 姓名，月份，日期，小时，分钟权重递减排序
bool cmp(node a, node b)
{
	// 
	if(strcmp(a.name,b.name) != 0)
	{
		return strcmp(a.name,b.name) < 0; // 姓名字典序递增排序
	}

	else if(a.month != b.month)
	{
		return a.month < b.month;
	}
	else if(a.day != b.day)
	{
		return a.day < b.day;
	}
	else if(a.hour != b.hour)
	{
		return a.hour < b.hour;
	}
	else 
	{
		return a.minute < b.minute;
	}
}


void get_ans(int on,int off, int &time, int &money)
{
	temp = rec[on];
	while(temp.day < rec[off].day || temp.hour < rec[off].hour || temp.minute < rec[off].minute)
	{
		time++;
		money += rates[temp.hour];
		temp.minute++;
		if(temp.minute >= 60)
		{
			temp.minute = 0;
			temp.hour++;
		}

		if(temp.hour >= 24)
		{
			temp.hour = 0;
			temp.day++;
		}
	}
}

// 先从输入数据开始编码
int main()
{
	int n; // 记录条数
	char line[10]; // 临时存放是否在线的状态
	// 输入费率数据
	for(int i = 0; i < 24; i++)
	{
		scanf("%d",&rates[i]); 
	}

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].day,&rec[i].hour,&rec[i].minute);
		scanf("%s",line);
		if(strcmp(line,"on-line") == 0)
		{
			rec[i].status = true;
		} 
		else
		{
			rec[i].status = false;
		}
	}

	// 排序
	sort(rec,rec+n,cmp); 

	int on = 0, off, next; // on和off为配对的两条记录，next是下个用户
	while(on < n)
	{
		int needPrint = 0;
		next = on;
		while(next < n && strcmp(rec[next].name,rec[on].name) == 0)
		{
			if(needPrint == 0 && rec[next].status == true)
			{
				needPrint = 1;
			}
			else if(needPrint == 1 && rec[next].status == false)
			{
				needPrint = 2;
			}
			next++;
		}
		if(needPrint < 2)
		{
			on = next;
			continue;
		}

		int AllMoney = 0;
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on < next)
		{
			while(on < next - 1 && !rec[on].status == true && rec[on + 1].status == false)
			{
				on++;
			}
			off = on + 1;
			if(off == next)
			{
				on = next;
				break;
			}

			printf("%02d:%02d:%02d ", rec[on].day,rec[on].hour,rec[on].minute);
			printf("%02d:%02d:%02d ", rec[off].day,rec[off].hour,rec[off].minute);
			
			int time = 0, money = 0;
			get_ans(on,off,time,money);
			AllMoney += money;
			printf("%d $%.2f\n",time,money / 100.0);
			on = off + 1;
		}

		printf("Total amount: $%.2f\n", AllMoney / 100.0);
	}

	return 0;
}