#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 100010
vector<vector<int>> vt;
int n, m;
int seg[MAX_N<<2], lazy[MAX_N<<2];
int S[100010];
int E[100010];
int cnt;
int dfs(int curr)
{
	S[curr] = E[curr] = ++cnt;
	for (int i = 0; i < vt[curr].size(); i++)
	{
		if(!S[vt[curr][i]])
			E[curr] = max(E[curr], dfs(vt[curr][i]));
	}
	return E[curr];
}
void lazy_update(int node, int x, int y)
{
	if (lazy[node] == 0) return;
	if ((y - x + 1) % 2)
	{
		seg[node] ^= lazy[node];
	}
	if (x != y)
	{
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	lazy[node] = 0;
}
int update(int node,int lo, int hi, int x, int y, int val)
{
	lazy_update(node, x, y);
	if (hi < x || y < lo)
	{
		return seg[node];
	}
	if (lo <= x && y <= hi)
	{
		lazy[node] ^= val;
		lazy_update(node, x, y);
		return seg[node];
	}
	int mid = (x + y) >> 1;
	return seg[node] = update(node * 2,lo,hi, x, mid,val) ^ update(node * 2 + 1,lo,hi, mid + 1, y,val);
}
int query(int node,int lo, int hi, int x, int y)
{
	lazy_update(node, x, y);
	if (hi < x || y < lo)
	{
		return 0;
	}
	if (lo <= x && y <= hi)
	{
		return seg[node];
	}
	int mid = (x + y) >> 1;
	return query(node * 2, lo, hi, x, mid) ^ query(node * 2 + 1, lo, hi, mid + 1, y);
}

int main()
{
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	int prev, next;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &prev, &next);
		vt[prev].push_back(next);
		vt[next].push_back(prev);
	}
	dfs(1);
	
	int menu, x, y;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		update(1, S[i], S[i], 1, n, x);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &menu);
		if (menu == 1)
		{
			scanf("%d", &x);
			printf("%d\n", query(1, S[x], E[x], 1, n));
		}
		else
		{
			scanf("%d %d", &x, &y);
			update(1, S[x], E[x], 1, n, y);
		}
	}

	return 0;
}