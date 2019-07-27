#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
int n, m, a, b,t;
vector<vector<pair<int,int>>> vt;
vector<pair<int,int>> path;
bool check[1001];
int main()
{
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &t);
		vt[a].push_back({ b,t });
		vt[b].push_back({ a,t });
	}
	// 최단 경로에 속하는 경로중 하나를 없애는 수 밖에 없다.
	int min_dist = 0;
	priority_queue < pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(1, 1)));
	while (!pq.empty())
	{
		int here = pq.top().second.first;
		int prev = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		if (check[here]) continue;
		check[here] = 1;
		if (here != prev) path.push_back({ prev,here });
		if (here == n) min_dist = cost;
		for (int i = 0; i < vt[here].size(); i++)
		{
			int next = vt[here][i].first;
			int next_cost = -cost - vt[here][i].second;
			if (!check[next])
			{
				pq.push({ next_cost,{next,here} });
			}
		}
	}

	int res = 0;
	for (int i = 0; i < path.size(); i++)
	{
		int prev = path[i].first;
		int next = path[i].second;
		memset(check, 0, sizeof(check));
		priority_queue<pair<int, int>> p;
		p.push({ 0,1 });
		while (!p.empty())
		{
			int here = p.top().second;
			int cost = -p.top().first;
			p.pop();
			if (check[here]) continue;
			check[here] = 1;
			if (here == n) res = max(res, cost - min_dist);
			for (int j = 0; j < vt[here].size(); j++)
			{
				int n = vt[here][j].first;
				int next_cost = -cost - vt[here][j].second;
				if (!check[n])
				{
					if (here == prev && n == next) continue;
					p.push({ next_cost,n });
				}
			}
		}

		if (!check[n])
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", res);

	return 0;
}