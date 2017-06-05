#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	char s[50];
	char back[50];
	double temp,sum = 0.0;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%s",s);
		sscanf(s,"%lf",&temp); // 将读取的字符数组写入temp，如果是 aaa -> 0.000000, 3.2.3 -> 3.200000
		sprintf(back,"%.2lf",temp); // 将temp以两位小数格式写入back字符数组
		int len = strlen(s);
		bool flag = false;
		for(int j = 0; j < len; j++)
		{
			if(s[j] != back[j])
			{
				flag = true;
			}
		}
		if(flag || temp < -1000 || temp > 1000)
		{
			printf("ERROR: %s is not a legal number\n", s);
		}
		else
		{
			cnt++; //计数
			sum += temp; //这样通过sscanf格式化直接取出来浮点数了
		}
	}

	if(cnt == 0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(cnt == 1)
	{
		printf("The average of 1 number is %.2lf\n",sum);
	}
	else
	{
		printf("The average of %d numbers is %.2lf\n",cnt,sum / cnt);
	}
	return 0;
}


// #include <iostream>
// #include <cstdio>
// #include <string.h>
// using namespace std;
// int main() {
//     int n, cnt = 0;
//     char a[50], b[50];
//     double temp, sum = 0.0;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         scanf("%s", a);
//         sscanf(a, "%lf", &temp);
//         sprintf(b, "%.2lf",temp);
//         int flag = 0;
//         for(int j = 0; j < strlen(a); j++) {
//             if(a[j] != b[j]) {
//                 flag = 1;
//             }
//         }
//         if(flag || temp < -1000 || temp > 1000) {
//             printf("ERROR: %s is not a legal number\n", a);
//             continue;
//         } else {
//             sum += temp;
//             cnt++;
//         }
//     }
//     if(cnt == 1) {
//         printf("The average of 1 number is %.2lf", sum);
//     } else if(cnt > 1) {
//         printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
//     } else {
//         printf("The average of 0 numbers is Undefined");
//     }
//     return 0;
// }