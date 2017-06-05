#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1000010;
int heap[maxn] = {0};
int n; // n是实际序列的个数

void downAdjust(int low, int high) // low是待调整的结点下标，high是最后一个结点的下标
{
	int i = low, j = 2 * i;
	while(j <= high) // 如果j超多了high，表示已经没有孩子了
	{
		// 比较左右孩子谁大
		if(heap[j] < heap[j + 1] && j + 1 <= high) // j : 左孩子， j + 1 : 右孩子
		{
			j = j + 1;
		}

		if(heap[i] < heap[j]) // 队长的值小于最大的孩子结点，则交换
		{
			swap(heap[i],heap[j]);
			i = j;
			j = 2 * i;
		}
		else
		{
			break;
		}
	}
}

void upAdjust(int low, int high) // high是待调整的结点下标
{
	int i = high, j = i / 2;
	while(j >= low) // 父结点在[low, high]之间
	{
		if(heap[i] > heap[j]) //注意i指向的是最后一个结点，j指向的是其父结点，孩子比父亲大则不符合堆的性质
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
	heap[++n] = x; // 往后加个位置，然后把新来的数据加上去
	upAdjust(1,n);// n是待调整的数据
}

void deleteTop()
{
	// 删除堆顶元素
	heap[1] = heap[n--]; //用最后的元素覆盖堆顶，然后向下调整
	downAdjust(1,n);// 注意此时的n的值已经是n-1了
}

void createHeap()
{
	// 创建堆意思是对初始堆进行调整，数据已经准备好的，这个步骤确保的是符合堆的性质
	for(int i = n / 2; i >= 1; i--)
	{
		downAdjust(i,n); // i是待调整的结点下标：最后一个有孩子的结点，n是最后一个元素的下标
	}
}

void heapSort()
{
	createHeap();
	for(int i = n; i > 1; i--)
	{
		swap(heap[i],heap[1]); //交换heap[i] 与heap[1]
		downAdjust(1,i - 1); // 调整堆顶
	}
}

int main()
{
	n = 10;
	for(int i = 1; i <= n;i++)
	{
		heap[i] = i;
	}

	for(int i = 1; i <= n; i++)
	{
		printf("%d", heap[i]);
		if(i < n)
		{
			printf(" ");
		}
	}

	printf("\n");
	createHeap();
	for(int i = 1; i <= n; i++)
	{
		printf("%d", heap[i]);
		if(i < n)
		{
			printf(" ");
		}
	}
	printf("\n");

	heapSort();
	for(int i = 1; i <= n; i++)
	{
		printf("%d", heap[i]);
		if(i < n)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}