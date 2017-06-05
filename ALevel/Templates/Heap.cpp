#include <stdio.h>
#include <algorithm>

using namespace std;

void downAdjust(int low, int high) // low:待调整的结点下标，high:一般为最后一个结点的下标
{
	int i = low, j = 2 * i;
	while(j <= high) // 存在孩子
	{
		// 找到左右孩子较大的下标:首先需要确定的是有右孩子，否则就会越界访问
		if(j + 1 <= high && heap[j + 1] > heap[j])
		{
			j = j + 1;
		}

		// 如果孩子中最大的结点大于待调整的结点
		if(heap[j] > heap[i])
		{
			swap(heap[j], heap[i]); //此时i,j的指示结点换了
			i = j;
			j = 2 * i;
		}
		else
		{
			break; // 不用调整了，结束循环
		}
	}
}

// 建堆
void createHeap()
{
	for(int i = n / 2; i >= 1; i--) // 从最后一个有孩子的开始调整
	{
		downAdjust(i,n); // i--表示从右往左调整，根下标是1，这个一定需要注意清楚
	}
}

// 删除堆顶元素
void deleteTop()
{
	heap[1] = heap[n--];// 用最后一个元素覆盖堆顶元素，并让元素个数减1
	downAdjust(1,n);//向下调整堆顶元素,此时的n已经是n-1了
}

// 往堆中添加元素:上调, 逻辑相对简单一点
void upAdjust(int low, int high)
{
	int i = high, j = i / 2;
	while(j >= low)
	{
		if(heap[j] < heap[i]) // 只与堆顶比较
		{
			swap(heap[i], heap[j]);
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
	heap[++n] = x; // 先让n自增，把元素放在最后一位，开始往上调整
	upAdjust(1,n);
}

int main()
{
	return 0;
}