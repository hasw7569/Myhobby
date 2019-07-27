#include<stdio.h>
#include<vector>
using namespace std;
int n,m;
vector<vector<int>> vt;
bool check[101];
int cnt;
void dfs(int here)
{
	check[here] = 1;
	cnt++;
	for (int i = 0; i < vt[here].size(); i++)
	{
		if (!check[vt[here][i]])
		{
			dfs(vt[here][i]);
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	dfs(1);
	printf("%d\n", cnt - 1);
	return 0;
}