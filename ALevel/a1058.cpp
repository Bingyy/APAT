#include <stdio.h>

int a[3],b[3],c[3]; // a[2]存储最低位

int main()
{
	scanf("%d.%d.%d %d.%d.%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);

	int carry = 0;
	c[2] = (a[2] + b[2]) % 29; //直接加没有进位可加
	carry = (a[2] + b[2]) / 29; //计算个位出现的进位
	c[1] = ((a[1] + b[1]) + carry) % 17; // 不仅加当前位置的数据还加上进位
	carry = (a[1] + b[1] + carry) / 17;// 当前进位
	c[0] = a[0] + b[0] + carry;
	printf("%d.%d.%d\n", c[0],c[1],c[2]);
	return 0;
}