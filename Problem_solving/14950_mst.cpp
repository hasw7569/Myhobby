#include<stdio.h>
#include<vector>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, t;
int A, B, C;
vector<pair<int, pair<int, int>>> vt;
int par[10001];
int find(int a)
{
	if (par[a] == -1) return a;
	return par[a] = find(par[a]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == -1 && b == -1 || a != b)
	{
		par[a] = b;
		return true;
	}
	return false;
}
int main()
{
	memset(par, -1, sizeof(par));
	scanf("%d %d %d", &n, &m, &t);
	int res = (n == 1) ? 0 : (((n - 1) * ((n - 2)*t)) / 2);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		vt.push_back({ C,{A,B} });
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++)
	{
		if (merge(vt[i].second.first, vt[i].second.second)) res += vt[i].first;
	}
	printf("%d\n", res);
	return 0;
}