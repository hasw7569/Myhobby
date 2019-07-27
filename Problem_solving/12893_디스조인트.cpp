#include<stdio.h>
#include<vector>
using namespace std;
int N, M;
int a, b;
vector<vector<int>> vt;
int par[2001];
int find(int a)
{
	return a == par[a] ? a : find(par[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[b] = a;
}
void func(int my, int enemy)
{
	for (int i = 0; i < vt[enemy].size(); i++)
	{
		int F = vt[enemy][i];
		if(F != my)
			merge(my, F);
	}
}
int main()
{
	for (int i = 1; i <= 2000; i++) par[i] = i;
	scanf("%d %d", &N, &M);
	vt.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < vt[i].size(); j++)
		{
			func(i, vt[i][j]);
		}
	}
	bool ok = true;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < vt[i].size(); j++)
		{
			if (find(i) == find(vt[i][j]))
			{
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	printf("%d\n", ok);
	return 0;
}