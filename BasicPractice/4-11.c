#include <stdio.h>

#define MAXN 10
typedef float ElementType;
int choose_pivot(int i,int j );
void swap(int *x,int *y);
void quicksort(int list[],int m,int n);


ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Median(ElementType A[], int N){
	//排序
	quicksort(A,0,N-1);

	if(N % 2 == 0){
		return (A[N/2]+A[N/2-1])/2;
	}
	else {
		return A[(N-1)/2];
	}
}



void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int choose_pivot(int i,int j )
{
   return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
   int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j)
                swap(&list[i],&list[j]);
      }
     // 交换两个元素的位置
      swap(&list[m],&list[j]);
     // 递归地对较小的数据序列进行排序
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);
   }
}