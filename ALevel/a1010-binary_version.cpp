#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL INF = (1LL << 63) - 1; 
LL HashTable[256]; // 将字符映射到数字

void init()
{
	for(char c = '0'; c <= '9';c++)
	{
		HashTable[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++)
	{
		HashTable[c] = c - 'a' + 10;
	}
}

LL convertNum10(char a[],LL radix, LL t) // t是上界
{
	LL ans = 0;
	int len = strlen(a);
	for(int i = 0; i < len; i++)
	{
		ans = ans * radix + HashTable[a[i]]; // 这就是标准的由digits转为10进制数的方法
		if(ans < 0 || ans > t) // 溢出或者超过N1的十进制
		{
			return -1;
		}
	}
	return ans;
}
int cmp(char N2[],LL radix, LL t) // t是N1的十进制
{
	// 都在十进制下比较
	int len = strlen(N2);
	LL num = convertNum10(N2,radix,t);
	if(num < 0)
	{
		return 1; // 溢出，N2 > t
	}
	if(t > num)
	{
		return -1;
	}
	else if(t == num) return 0; // 相等
	else return 1;// num较大
}

LL binarySearch(char N2[],LL left, LL right, LL t) // left, right, mid都是进制
{
	// 精确查找
	LL mid; 
	while(left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);
		if(flag == 0) return mid;
		else if(flag == -1) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}

int findLargestDigit(char N2[])
{
	int ans = -1, len = strlen(N2);
	for(int i = 0; i < len; i++)
	{
		if(HashTable[N2[i]] > ans)
		{
			ans = HashTable[N2[i]];
		} 
	}

	return ans + 1;
}


char N1[20],N2[20],temp[20];
int tag, radix;

int main(int argc, char const *argv[])
{
	init();
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	// 将N1人为化为基知道的值：交换的手段，N2是基数待解的值
	if(tag == 2) // 
	{
		swap(N1,N2); // 交换
	}

	LL t = convertNum10(N1,radix,INF); 
	LL low = findLargestDigit(N2); // 找到N2中数位最大的位加1，当做二分下界：下界不必从2开始枚举
	LL high = max(low,t) + 1;
	LL ans = binarySearch(N2,low,high,t);// 二分查找
	if(ans == -1)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%lld\n", ans);
	}
	return 0;
}
