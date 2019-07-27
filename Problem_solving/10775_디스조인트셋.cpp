#include<stdio.h>
int G, P;
int par[100001];
int query;
int find(int v)
{
	return v == par[v] ? par[v] : par[v] = find(par[v]);
}
void merge(int u, int v)
{
	u = par[u];
	v = par[v];
	if (u == v) return;
	par[v] = u;
}
int main()
{
	for (int i = 1; i <= 100000; i++)
		par[i] = i;
	scanf("%d %d", &G, &P);
	int res = 0;
	for (int i = 1; i <= P; i++)
	{
		scanf("%d", &query);
		int P = find(query);
		if (P == 0) break;
		merge(P - 1, P);
		res++;
	}
	printf("%d\n", res);

	return 0;
}