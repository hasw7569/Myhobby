#include<stdio.h>
int n, m;
int par[1000001];
int find(int v)
{
	if (par[v] == v)
		return v;
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
	for (int i = 0; i <= n; i++)
	{
		par[i] = i;
	}
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
		{
			merge(b, c);
		}
		else
		{
			b = find(b);
			c = find(c);
			if (b == c) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}