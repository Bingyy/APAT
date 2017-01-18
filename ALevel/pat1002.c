#include<stdio.h>
typedef struct{
	int ni;//指数
	double ani;//系数
} poly; //一锤子买卖，只定义了这一个结构体类型
int main(){
	int k1, k2;
	poly a[12],b[12],c[30];
	int i,j,pos;
	int t1;
	double t2;
	//这是一个冗余很高的代码实现，考虑到了边界的各种不同
	while(scanf("%d",&k1)!=EOF){
		//输入第一个多项式
		for(i = 0; i < k1; i++){
			scanf("%d %lf",&a[i].ni,&a[i].ani);
		}
		scanf("%d",&k2);
		for(i = 0; i < k2; i++){
			scanf("%d %lf",&b[i].ni, &b[i].ani);
		}

		pos = 0;
		for(i = 0, j = 0; i < k1 && j < k2;){
			if(a[i].ni == b[j].ni){
				t1 = a[i].ni;
				t2 = a[i].ani + b[j].ani;
				if(t2 != 0){
					c[pos].ni = t1;
					c[pos].ani = t2;
					pos++;
					i++;
					j++;
				}
				else{
					i++;
					j++;
				}
			}
			else if(a[i].ni > b[j].ni){
				t1 = a[i].ni;
				t2 = a[i].ani;
				if(t2 != 0){
					c[pos].ni = t1;
					c[pos].ani = t2;
					pos++;
					i++;
				}
				else{
					i++;
				}
			}
			else{
				t1 = b[j].ni;
				t2 = b[j].ani;
				if(t2 != 0){
					c[pos].ni = t1;
					c[pos].ani = t2;
					pos++;
					j++;
				}
				else{
					j++;
				}
			}
		}
		//剩余部分
		if(i < k1){
			for(; i < k1; i++){
				t1 = a[i].ni;
				t2 = a[i].ani;
				if(t2 != 0){
					c[pos].ni = t1;
					c[pos].ani = t2;
					pos++;
				}
			}
		}
		if(j < k2){
			for(; j < k2; j++){
				t1 = b[j].ni;
				t2 = b[j].ani;
				if(t2 != 0){
					c[pos].ni = t1;
					c[pos].ani = t2;
					pos++;
				}
			}
		}
		printf("%d",pos);
		for(i = 0; i < pos; i++){
			printf(" %d %.1lf",c[i].ni, c[i].ani);
		}
		printf("\n");
	}

	return 0;
}