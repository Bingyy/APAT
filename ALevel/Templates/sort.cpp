#include <cstdio>
#include <algorithm>

using namespace std;

// sort 函数可以用来排序数组
// sort(首元素地址：v.begin()，尾元素的下一个地址:v.end(),比较函数：非必须)
int main()
{
	int a[6] = {9,4,2,5,6,-1};
	sort(a,a+6);
	for(int i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
	return 0;
}