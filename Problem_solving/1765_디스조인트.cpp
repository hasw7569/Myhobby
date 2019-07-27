#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<int>> enemy;
int par[1001];
int n, m;
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
void func(int my, int E)
{
	for (int i = 0; i < enemy[E].size(); i++)
	{
		int F = enemy[E][i];
		if (F != my)
			merge(my, F);
	}
}
int main()
{
	for (int i = 1; i <= 1000; i++) par[i] = i;
	scanf(" %d %d", &n, &m);
	enemy.resize(n + 1);
	char C;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf(" %c", &C);
		scanf(" %d %d", &a, &b);
		if (C == 'E')
		{
			enemy[a].push_back(b);
			enemy[b].push_back(a);
		}
		else if (C == 'F')
		{
			merge(a, b);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < enemy[i].size(); j++)
		{
			func(i, enemy[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == par[i]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}