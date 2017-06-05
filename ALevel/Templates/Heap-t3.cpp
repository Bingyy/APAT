#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;

int heap[maxn] = {0};// 完全二叉树，所以从1开始往后存
int n;

void downAdjust(int low, int high)
{
	int i = low, j = i * 2;
	while(j <= high)
	{
		if(j + 1 <= high && heap[j + 1] > heap[j])
		{
			j = j + 1;
		}
		if(heap[j] > heap[i])
		{
			swap(heap[i],heap[j]);
			i = j;
			j = i * 2;
		}
		else
		{
			break;
		}
	}
}
void deleteTop() // 操作的也是heap数组
{
	heap[1] = heap[n--]; // 删除堆顶：拿最后一个元素替换堆顶，开始向下调整
	downAdjust(1,n); //此时的n已经是减过1的
}

void upAdjust(int low, int high)
{
	int i = high, j = i / 2; // 现在j是父结点
	while(i >= low) // 用循环控制不断调整到不用再调整为止
	{
		if(heap[i] > heap[j])
		{
			swap(heap[i],heap[j]);
			i = j;
			j = i / 2;
		}
		else
		{
			break;
		}
	}
}

void insert(int x)
{
	heap[++n] = x; // 扩充一个位置
	upAdjust(1,n);
}

void createHeap()
{
	// 数据是准备好的，建堆是说对这个原始的数据进行调整
	for(int i = n / 2; i >= 1; i--)
	{
		downAdjust(i,n);
	}
}

void heapSort()
{
	createHeap(); //建立初始堆
	for(int i = n; i > 1; i--) // 注意这种for循环是i--
	{
		swap(heap[i],heap[1]); // 最大值放到最后面了
		downAdjust(1, i - 1); // 调整剩下的部分，仍然是从堆顶调整，注意此时堆的最后一个元素是i-1
	}
}

int main()
{
	n = 10;
	for(int i = 1; i <= 10; i++)
	{
		heap[i] = i;
	}

	createHeap();

	for(int i = 1; i <= 10; i++)
	{
		printf("%d ", heap[i]);
	}

	printf("\n");

	heapSort();

	for(int i = 1; i <= 10; i++)
	{
		printf("%d ", heap[i]);
	}

	printf("\n");
	return 0;
}