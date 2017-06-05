// #include <stdio.h>
// #include <vector>

// using namespace std;

// 
// int* maxsequence(vector<int> a, int n)
// {
//     int maxSum, maxCur;
//     maxSum = maxCur = a[0];   //初始化最大和为a[0]
//     int* nums = new int[3];

//     for (int i = 1; i < n; i++) {
//         if (maxCur <= 0)//这里其实是maxCur+a[i]<= a[i]化简的版本
//         { 
//         	nums[1] = i;
//             maxCur = a[i];  //如果前面位置最大连续子序列和小于等于0，则以当前位置i结尾的最大连续子序列和为a[i]
//         }
//         else
//         {
//             maxCur += a[i]; //如果前面位置最大连续子序列和大于0，则以当前位置i结尾的最大连续子序列和为它们两者之和
//         }
//         if (maxCur > maxSum) 
//         {
//             maxSum = maxCur;  //更新最大连续子序列和
//             nums[0] = maxSum;
//             nums[2] = i;
//         }
//     }
//     return nums;
// }

// int main()
// {
// 	vector<int> ins;
// 	int k;
// 	int temp;
// 	scanf("%d",&k);
// 	for(int i = 0; i < k; i++)
// 	{
// 		scanf("%d", &temp);
// 		ins.push_back(temp);
// 	}

// 	int m = maxsequence1(ins, ins.size());

// 	int* res = maxsequence(ins,ins.size());

// 	printf("%d\n",m);
// 	printf("%d\n", res[0]);

// 	printf("%d ", res[1]);

// 	printf("%d\n", res[2]);

// 	// for(auto it = ins.begin(); it != ins.end(); it++)
// 	// {
// 	// 	printf("%d ", *it);
// 	// }
// 	return 0;
// }

// 非自己完成--留作参考

#include <vector>
using namespace std;
int main() {
    int n, flag = 0, sum = -1, temp = 0, left = 0, right = 0, tempindex = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if(v[i] >= 0)
            flag = 1;
        temp = temp + v[i];
        if(temp > sum) {
            sum = temp;
            left = tempindex;
            right = i;
        } else if(temp < 0) {
            temp = 0;
            tempindex = i + 1;
        }
    }
    if(flag == 0)
        printf("0 %d %d", v[0], v[n - 1]);
    else
        printf("%d %d %d", sum, v[left], v[right]);
    return 0;
}