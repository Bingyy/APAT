#include <cstdio>
#include <cctype>
using namespace std;

const int N = 202;

// 需要有编译原理的基础知识

char s[N];
int p = 0;

double exp();
double calc();

double calc()
{
  double res = 1.0;
  bool flag = 1;
  while (1) {
    double t;
    if (isdigit(s[p])) { // 如果是数字
      int cnt;
      sscanf(s + p, "%lf%n", &t, &cnt);
      p += cnt;
    } else if (s[p] == '(') {
      ++p;
      t = exp();
      ++p;
    }
    if (flag) {
      res *= t;
    } else {
      res /= t;
    }
    if (s[p] == '*') {
      flag = 1;
      ++p;
    } else if (s[p] == '/') {
      flag = 0;
      ++p;
    } else {
      break;
    }
  }

  return res;
}

double exp()
{
  double res = 0.0;
  bool flag = 1;
  while (1) {
    double t = calc();
    if (flag) {
      res += t;
    } else {
      res -= t;
    }
    if (s[p] == '+') {
      flag = 1;
      ++p;
    } else if (s[p] == '-') {
      flag = 0;
      ++p;
    } else {
      break;
    }
  }

  return res;
}

int main()
{
  scanf("%s", s);
  printf("%.2f\n", exp());

  return 0;
}