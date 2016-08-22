#include<math.h>
double f(int n, double a[], double x){
	double sum = 0.0;
	for(int i = 0; i<= n; i++){
		sum+= a[i] * pow(x,i);
	}
	return sum;
}