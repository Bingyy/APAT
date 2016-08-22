#include<stdio.h>
int main(){
	int hoge;
	int *hoge_p;

	hoge_p = &hoge;
	printf("hoge_p..%p\n",hoge_p);
	//指针加1
	hoge_p++;
	//输出指针的值
	printf("hoge_p..%p\n",hoge_p);
	printf("hoge_p..%p\n", hoge_p+3);
	return 0;
}