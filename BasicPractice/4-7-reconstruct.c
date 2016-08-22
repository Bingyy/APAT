#include<stdio.h>
#include<math.h>
#include<stdlib.h>


/// author: 王兵
///time:2016-8-22
///提交后是部分正确---where wrong?  得分： 18/20 测试点3未通过,应是一个意外情况没有处理


int IsTheNumber(const int N){
	int n = N;
	int result = 0;
	//no.1 : is n*n type
	//no.2 : split digits, at least two are the same
	double root = sqrt(N);
	int ce = ceil(root);
	int fl = floor(root);
	// printf("%f %d %d\n",root,ce,fl);
	if(ce != fl){
		result = 0;
	}
	else{
		
		//因为每一个元素都是0-9，所以可以采用水桶法，共需要十个桶
		int container[10];
		for(int i = 0; i < 10; i++){
			container[i] = 0;//初始化为0
		}
		while(n != 0){
			container[n % 10]++;
			n /= 10;
		}
		//遍历桶，如果有桶的元素大于等于2则返回true
		for(int i = 0; i < 10; i++){
			if(container[i] >= 2){
				result = 1;
			}
		}
	}
	return result;
}

int main()
{
    int n1, n2, i, cnt;
				
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}
