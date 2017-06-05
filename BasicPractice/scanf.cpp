#include <stdio.h>
int main()
{
    int a;
    char c, str[10];
    scanf("%d%c%s", &a, &c, str); // no need to use & for str, cause str is address
    printf("a=%d,c=%c,str=%s",a,c,str);
    return 0;
}
