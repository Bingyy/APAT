#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 310;
int n;
int l1, l2, l3, l4, sumL;

struct Student {
    char id[15];
    int g1, g2, g3, g4;
    int sumGrade;
}stu[maxn];

bool cmp(Student a, Student b) {
    if (a.sumGrade != b.sumGrade)
        return a.sumGrade > b.sumGrade;
    else
        return strcmp(a.id, b.id) < 0;
}
bool Judge(Student a) {
    if (a.g1 >= l1 && a.g2 >= l2 && a.g3 >= l3 && a.g4 >= l4 && a.sumGrade >= sumL)
        return true;
    else
        return false;
}
vector<Student> ans;
int main()
{
//  freopen("t1.txt", "r", stdin);
    scanf("%d %d %d %d %d", &l1, &l2, &l3, &l4, &sumL);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d %d", stu[i].id, &stu[i].g1, &stu[i].g2, &stu[i].g3, &stu[i].g4);
        stu[i].sumGrade = stu[i].g1 + stu[i].g2 + stu[i].g3 + stu[i].g4;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++) {
        bool res = Judge(stu[i]);
        if (res == true) {
            ans.push_back(stu[i]);
        }
    }

    printf("%d\n", ans.size());
    sort(ans.begin(),ans.end(),cmp);
    for (int i = 0; i < ans.size(); i++) {
        printf("%s %d\n", ans[i].id, ans[i].sumGrade);
        
    }

    return 0;
}