#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;
				
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
//递归算法太慢，不能全部通过，需要用循环算法
int Factorial(const int N){
	if(N == 1 || N == 0){
		return 1;
	}
	if(N < 0){
		return 0;
	}
	int product = 1;
	for(int i = 2; i <=N; i++){
		product *= i;
	}
	return product;
}