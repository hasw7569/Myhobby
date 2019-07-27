#include<stdio.h>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector<vector<pair<int, int>>> vt;
int n, m;
int src, dest;
bool check[10001];
bool bfs(int weight)
{
	memset(check, 0, sizeof(check));
	queue<int> que;
	check[src] = 1;
	que.push(src);
	while (!que.empty())
	{
		int curr = que.front();
		que.pop();
		for (int i = 0; i < vt[curr].size(); i++)
		{
			int next = vt[curr][i].first;
			int cost = vt[curr][i].second;
			if (!check[next] && cost >= weight)
			{
				check[next] = 1;
				que.push(next);
			}
		}
	}
	if (check[dest]) return true;
	return false;
}
int main()
{
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	int low = 1;
	int high = 1000000000;
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}
	scanf("%d %d", &src, &dest);

	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (bfs(mid))
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	printf("%d\n", low - 1);
	return 0;
}