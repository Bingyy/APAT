#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<int> st;
int main()
{
	int n; // n次查询
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		char cmd[15];
		int key;
		// cin >> cmd;
		scanf("%s", cmd);
		if(strcmp(cmd,"Push") == 0)
		{
			scanf("%d", &key); //如果是push命令，则继续输入数据
			st.push_back(key);
		}
		if(st.size() == 0 && strcmp(cmd,"Pop") == 0)
		{
			printf("Invalid\n");
		}
		else if(strcmp(cmd, "PeekMedian") == 0 && st.size() == 0)
		{
			printf("Invalid\n");
		}
		else if(strcmp(cmd, "Pop") == 0 && st.size() != 0)
		{
			printf("%d\n",st[st.size() - 1]);
			st.pop_back();
		}
		else if(strcmp(cmd,"PeekMedian") == 0 && st.size() != 0)
		{
			int size = st.size();
			if(size % 2 == 0)
			{
				printf("%d\n",st[(size / 2) - 1] );
			}
			else
			{
				printf("%d\n",st[((size + 1) / 2) - 1]);
			}
		}
	}
	return 0;
}
