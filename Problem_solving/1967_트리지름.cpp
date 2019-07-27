#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstring>
using namespace std;
vector<vector<pair<int,int>>> vt;
int n;
int max_dist;
int max_node;
bool check[10001];
void bfs(int curr, int cost)
{
	check[curr] = 1;
	if (max_dist < cost)
	{
		max_dist = max(max_dist, cost);
		max_node = curr;
	}
	for (int i = 0; i < vt[curr].size(); i++)
	{
		int next = vt[curr][i].first;
		int next_cost = cost + vt[curr][i].second;
		if(!check[next])
		bfs(next, next_cost);
	}
}
int main()
{
	scanf("%d", &n);
	vt.resize(n + 1);
	int par, child, dist;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &par, &child, &dist);
		vt[par].push_back({ child,dist });
		vt[child].push_back({ par,dist });
	}
	bfs(1, 0);
	// 첫번째 bfs에서 root에서 가장 멀리 떨어진 node를 찾는다.
	memset(check, 0, sizeof(check));
	max_dist = 0;

	bfs(max_node, 0);
	printf("%d\n", max_dist);
	return 0;
}