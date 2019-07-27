#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>> vt;
int val[1001];
int check[1001];
int t,n;
int cnt;
void dfs(int here)
{
	if (check[here])
	{
		if (check[here] = 1) cnt++; // check 되었는데 아직 끝나지는 않은경우
	}
	else
	{
		check[here] = 1; // check
		for (int i = 0; i < vt[here].size(); i++)
		{
			dfs(vt[here][i]);
		}
		check[here] = -1; // 끝나면 -1
	}
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		cnt = 0;
		memset(check, 0, sizeof(check));
		scanf("%d", &n);
		vt.clear();
		vt.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &val[i]);
			vt[i].push_back(val[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!check[i]) dfs(i);
		}
		printf("%d\n", cnt);
	}

	return 0;
}