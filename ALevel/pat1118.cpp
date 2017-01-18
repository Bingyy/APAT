#include <cstdio>
using namespace std;
int n, m, k;
const int maxn = 10010;
int fa[maxn] = {0};

bool boolHash[maxn] = {0}; //用于标记树存在

int findFather(int x) {
    int r = x;
    while(r != fa[r]) {
        r = fa[r];
    }
    int i = x,temp; //
  //压缩路径以提高效率，不然部分超时
    while(i != r) {
        temp = fa[i];
        fa[i] = r;
        i = temp;
    }
    return r;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        fa[faA] = faB;
    }
}


bool exist[maxn]; //标记已经出现的鸟的编号

int main() {

    scanf("%d", &n);//n幅图片

    for(int i = 1; i <= maxn; i++) {//将元素初始化为自己
        fa[i] = i;
    }

    int id, temp;

    for(int i = 0; i < n; i++) {

        scanf("%d%d", &k, &id);//每幅图片上k个鸟

        exist[id] = true; //第一个是老大，所以特别

        for(int j = 0; j < k-1; j++) {
            scanf("%d", &temp);
            Union(id, temp); //放到和第一个鸟同一棵树，Union的写法不必前者是老大，只是表明属于同一个树
            exist[temp] = true; 
        }
    }

    int numTrees = 0, numBirds = 0;

    for(int i = 1; i <= maxn; i++) {
        if(exist[i] == true) { // 鸟的编号存在
            numBirds++;// 统计鸟的总数
            int root = findFather(i);
            boolHash[root] = true; // 哈希：鸟已经按照分组分好了，且每一组都选好的代表，只标记代表为true,用于统计树的个数
        }
    }

    for(int i = 0; i <= maxn; i++) // boolHash为真的就是一棵树
    {
        if(boolHash[i])
        {
            numTrees++;
        }
    }

    printf("%d %d\n", numTrees, numBirds);

    scanf("%d", &m);//m组查询，每组是两个鸟
    int ida, idb;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &ida, &idb);
        if(findFather(ida) == findFather(idb)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}