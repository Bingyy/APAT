//借助strtok实现split
#include <string.h>
#include <stdio.h>
// #include <vector>

// using namespace std;

int strToNum(char str[])
{
    int n = strlen(str);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = 10 * ans + str[i] - '0';
    }
    return ans;
}


int main()
{
    char s[] = "3+(12/(2*2+1))";
    const char *d = "+-*/()";
    char *p;
    // p = strtok(s,d); // 线程不安全
    p = strtok(s,d); // 如果发现在d中的字符，会把s字符串中的字符替换为NULL

    while(p)
    {
        printf("%d\n",strToNum(p));// 输出第一个分割字符前的字符
        p = strtok(NULL,d); // 
    }

    return 0;
}