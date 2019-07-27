#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>> vt;
int n, m;
bool check[501];
int edge;
int vertex;
bool cycle;
void dfs(int curr)
{
	check[curr] = 1;
	vertex++; // 방문하는 모든 정점 count
	for (int i = 0; i < vt[curr].size(); i++)
	{
		int next = vt[curr][i];
		edge++; // 도중에 만나는 모든 간선 count
		if(!check[next])
		dfs(next);
	}
}
int main()
{
	int st = 0;
	while (1)
	{
		st++;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		memset(check, 0, sizeof(check));
		vt.clear();
		vt.resize(n + 1);
		int prev, next;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &prev, &next);
			vt[prev].push_back(next);
			vt[next].push_back(prev);
		}
		int tree = 0;
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
			{
				cycle = 0;
				vertex = 0;
				edge = 0;
				dfs(i);
				if (!cycle && (vertex == edge/2 + 1)) tree++; // 양방향 간선으로 하였으므로 edge/2를 해준다.
			}
		}

		if (tree == 0)
		{
			printf("Case %d: No trees.\n", st);
		}
		else if (tree == 1)
		{
			printf("Case %d: There is one tree.\n", st);
		}
		else
		{
			printf("Case %d: A forest of %d trees.\n", st, tree);
		}
	}


	return 0;
}