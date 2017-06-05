#include <stdio.h>

int main()
{
	/* code */
	// int n;
	// char str[50] = "123";

	// int m = 1234;

	// printf("%s\n", str);

	// sscanf(str,"%d",&n);
	
	// sprintf(str,"%d",n);

	// printf("%s\n", str);

	// char sztime1[16] = "", sztime2[16] = "";
	// sscanf("2006:03:18 - 2006:04:18", "%s - %s", sztime1, sztime2);
	// printf("%s\n",sztime1);
	// printf("%s\n", sztime2);
	char a[50] = "3.2.3";
	char b[50];
	double temp;
	sscanf(a,"%lf",&temp); // 把字符串a以浮点数格式读入temp，默认的%lf有六个小数点
	sprintf(b,"%.2lf",temp); // 限制写入b字符数组的只有两个小数点

	printf("%lf\n", temp);
	printf("%s\n", a);
	printf("%s\n",b);
	return 0;
}