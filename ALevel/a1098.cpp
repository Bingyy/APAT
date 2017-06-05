#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 111;
int origin[maxn],tempOri[maxn],changed[maxn]; // 原始数组，原始数组备份，目标数组
int n; // 元素个数
bool isSame(int a[], int b[])
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != b[i]) return false;
	}
	return true;
}

void showArray(int a[])
{
	for(int i = 1; i <= n; i++)
	{
		printf("%d", a[i]);
		if(i < n) printf(" ");
	}
	printf("\n");
}
bool insertSort()
{
	bool flag = false;
	for(int i = 2; i <= n; i++)
	{
		if(i != 2 && isSame(tempOri,changed)) // 中间步骤与目标相同
		{
			flag = true; // 在flag已经为true时，仍然进行了一轮排序，因为输出的是下一步骤的序列
		}
		// 插入部分用sort代替
		sort(tempOri,tempOri + i + 1);
		if(flag == true)
		{
			return true;
		}
	}
	return false;
}
void downAdjust(int low, int high)
{
	int i = low, j = i * 2;
	while(j <= high)
	{
		if(j + 1 <= high && tempOri[j + 1] > tempOri[j])
		{
			j = j + 1;
		}
		if(tempOri[j] >= tempOri[i])
		{
			swap(tempOri[j], tempOri[i]);
			i = j;
			j = i * 2;
		}
		else
		{
			break;
		}
	}
}

void heapSort()
{
	bool flag = false;
	for(int i = n / 2; i >= 1; i--)
	{
		downAdjust(i,n); // 建堆
	}
	for(int i = n; i > 1; i--)
	{
		if(i != n && isSame(tempOri,changed))
		{
			flag = true; 
		}
		swap(tempOri[i],tempOri[1]); // flag为true有仍然再进行一轮排序，所以最终可以输出的是tempOri数组
		downAdjust(1, i - 1);
		if(flag == true) // 已经达到目标数组
		{
			showArray(tempOri);
			return;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&origin[i]); // 输入起始数组
		tempOri[i] = origin[i]; // 打个备份，用作中间存储排序序列
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&changed[i]);//目标数组
	}
	if(insertSort())
	{
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else
	{
		printf("Heap Sort\n");
		for(int i = 1; i <= n; i++)
		{
			tempOri[i] = origin[i]; // 还原tempOri数组
		}
		heapSort();// 进行堆排序
	}
	return 0;
}