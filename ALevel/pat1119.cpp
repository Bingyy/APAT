#include <cstdio>
#include <vector>
using namespace std;
vector<int> ans; //存储中序序列
int *pre, *post, unique = 1;


int mapIndex[256];
void mapToIndices(int pre[], int n)
{
    int i;
    for (i=0; i<n; i++) {
        mapIndex[pre[i]] = i;
    }
}

// int findFromPre (int x, int l, int r) 
// {
//   for (int i = l; i <= r; i++) {
//     if (x == pre[i]) {
//       return i;
//     }
//   }
//   return -1;
// }

void setIn(int prel, int prer, int postl, int postr) {
  if (prel == prer) //通过下标夹逼的方式锁定中序
  {
    ans.push_back(pre[prel]);
    return;
  }

  if (pre[prel] == post[postr]) 
  {
    // int x = findFromPre(post[postr - 1], prel + 1, prer);
    
    int x = mapIndex[post[postr-1]];

    if (x - prel > 1) {
      setIn(prel + 1, x - 1, postl, postl + x - prel - 2);
      ans.push_back(post[postr]);
      setIn(x, prer, postl + x - prel - 2 + 1, postr - 1);
    } 

    else {
      unique = 0;
      ans.push_back(post[postr]);
      setIn(x, prer, postl + x - prel - 2 + 1, postr - 1);
    }
  } 
}

int main() {
  int n = 0;
  scanf("%d", &n);
  pre = new int [n];
  post = new int [n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &pre[i]);
  }
  mapToIndices(pre,n);//将先序序列打到哈希表，使得查询为O(1)

  for (int i = 0; i < n; i++) {
    scanf("%d", &post[i]);
  }

  setIn(0, n - 1, 0, n - 1);
  printf("%s\n", unique ? "Yes" : "No");
  printf("%d", ans[0]);

  for (int i = 1; i < ans.size(); i++) {
    printf(" %d", ans[i]);
  }
  printf("\n");
  return 0;
}