#include<stdio.h>
int n, m;
int par[201];
int find(int v)
{
	if (par[v] == v)
	{
		return v;
	}
	return par[v] = find(par[v]);
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u != v)
	{
		par[u] = v;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
	}
	int con;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &con);
			if (con) merge(i, j);
		}
	}
	int travel[1001];
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &travel[i]);
		if (i >= 2)
		{
			int a = find(travel[i]);
			int b = find(travel[i - 1]);
			if (a != b)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}