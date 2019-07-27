#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> vt;
int N;
int par[100001];
bool check[100001];
int main()
{
	scanf("%d", &N);
	vt.resize(N + 1);
	int prev, next;
	for (int i = 0; i < N-1; i++)
	{
		scanf("%d %d", &prev, &next);
		vt[prev].push_back(next);
		vt[next].push_back(prev);
	}

	queue<int> bfs;
	bfs.push(1);
	check[1] = 1;
	while (!bfs.empty())
	{
		int here = bfs.front();
		bfs.pop();
		for (int i = 0; i < vt[here].size(); i++)
		{
			int next = vt[here][i];
			if (!check[next])
			{
				check[next] = 1;
				par[next] = here;
				bfs.push(next);
			}
		}
	}
	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", par[i]);
	}
	return 0;
}