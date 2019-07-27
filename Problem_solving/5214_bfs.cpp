#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
#define INF 987654321
int n, k, m;
vector<vector<int>> vt;
bool check[101010];
int res = INF;
int main()
{
	scanf("%d %d %d", &n, &k, &m);
	vt.resize(n + m + 1);
	// 하이퍼 튜브로 갈때는 가중치 0, 역으로 갈때는 가중치 1

	for (int i = n + 1; i <= n + m; i++)
	{
		int temp;
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &temp);
			vt[i].push_back(temp);
			vt[temp].push_back(i);
		}
	}
	queue<pair<int, int>> bfs;
	check[1] = 1;
	bfs.push({ 1,1 });
	while (!bfs.empty())
	{
		int curr = bfs.front().first;
		int cost = bfs.front().second;
		bfs.pop();
		if (curr == n)
		{
			res = min(res, cost);
			break;
		}
		for (int i = 0; i < vt[curr].size(); i++)
		{
			int next = vt[curr][i];
			if (!check[next])
			{
				check[next] = 1;
				if (next <= n)
					bfs.push({ next,cost + 1 });
				else
					bfs.push({ next,cost });
			}
		}
	}
	if (res == INF) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}