#include<stdio.h>
#include<math.h>

int IsTheNumber(const int N){
	int n = N;
	//no.1 : is n*n type
	//no.2 : split digits, at least two are the same
	double root = sqrt(N);
	int ce = ceil(root);
	int fl = floor(root);
	// printf("%f %d %d\n",root,ce,fl);
	if(ce != fl){
		return 0;
	}
	else{
		int a[9];
		for(int i = 0; i < 9; i++){
			a[i] = n % 10;
			n = n / 10;
		}
		for(int j = 0; j < 9; j++){
			for(int k = 1; k < 9; k++){
				if(j != k && a[j] == a[k]){
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){

	int num;
	printf("%s", "Enter an integer: ");
	scanf("%d",&num);
	int res = IsTheNumber(num);
	printf("%d\n", res);
	return 0;
}
