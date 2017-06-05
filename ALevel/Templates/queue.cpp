#include <iostream>
// #include <vector>
#include <queue>
#include <string>

using namespace std;

struct fruit
{
	string name;
	double price;
	// friend bool operator< (fruit f1, fruit f2)
	// {
	// 	return f1.price < f2.price; // 相当于less,这是大顶堆，反之则是小顶堆
	// }
} f1, f2, f3; //定义三个结构体变量

struct cmp
{
	bool operator () (fruit f1, fruit f2) // 重载括号
	{
		return f1.price < f2.price;
	}
};
int main()
{
	// priority_queue<int, vector<int> ,greater<int> >  q;
	// q.push(3);
	// q.push(2);
	// q.push(1);

	// printf("%d\n", q.top());
	// 结构体优先级


	priority_queue<fruit,vector<fruit> , cmp > q;

	f1.name = "Peach";
	f1.price = 1.0;
	f2.name = "Orange";
	f2.price = 3.0;
	f3.name = "Watermelon";
	f3.price = 4.0;

	q.push(f1);
	q.push(f2);
	q.push(f3);


	cout << q.top().name << " " << q.top().price << endl;
	return 0;
}