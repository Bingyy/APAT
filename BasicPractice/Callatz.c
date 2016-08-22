#include<stdio.h>
int main()
{
  int n;
  scanf("%d", &n);
  int count = 0;
  while(n != 1)
  {
      return count;
  }
  if(n % 2 == 0)
  {
    n /= 2;
    count++;
  }
  else
  {
    n = (3*n + 1) / 2;
    count++;
  }
  return 0;
}