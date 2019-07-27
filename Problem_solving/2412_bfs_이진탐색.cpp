#include<stdio.h>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321
int n, T;
int x_move[24] = { 1,2,-1,-2,0,0,0,0,1,1,-1,-1,2,2,-2,-2,1,1,-1,-1,2,2,-2,-2 };
int y_move[24] = { 0,0,0,0,1,2,-1,-2,1,-1,1,-1,2,-2,2,-2,2,-2,2,-2,1,-1,1,-1 };
vector<pair<int, int>> vt;
bool check[50010];
int main()
{
	scanf("%d %d", &n, &T);
	int x, y;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		vt.push_back({ x,y });
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());
	queue<pair<pair<int, int>,int>> bfs;
	bfs.push({ {0,0},0 });
	int res = INF;
	while (!bfs.empty())
	{
		pair<int, int> curr = bfs.front().first;
		int cost = bfs.front().second;
		bfs.pop();
		if (curr.second >= T)
		{
			res = min(res, cost);
			continue;
		}
		for (int i = 0; i < 24; i++)
		{
			pair<int, int> next = { curr.first + x_move[i],curr.second + y_move[i] };
			
			if (binary_search(vt.begin(), vt.end(), next))
			{
				int check_pos = lower_bound(vt.begin(), vt.end(), next) - vt.begin();
				if (check[check_pos]) continue;
				check[check_pos] = 1;
				bfs.push({ next,cost + 1 });

			}
		}
	}
	if (res == INF) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}