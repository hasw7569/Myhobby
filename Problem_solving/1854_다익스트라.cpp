#include<stdio.h>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, k;
vector<vector<pair<int,int>>> vt;
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	vt.resize(n + 1);
	int prev, next,cost;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &prev, &next, &cost);
		vt[prev].push_back(make_pair(next, cost));
	}

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	vector<vector<int>> res;
	res.resize(n + 1);
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (res[curr].size() == k) continue;
		res[curr].push_back(cost);
		for (int i = 0; i < vt[curr].size(); i++)
		{
			int next = vt[curr][i].first;
			int next_cost = vt[curr][i].second;
			if (res[next].size() == k) continue;
			pq.push(make_pair(-cost - next_cost, next));
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (res[i].size() < k) printf("-1\n");
		else printf("%d\n", res[i][k - 1]);
	}

	return 0;
}