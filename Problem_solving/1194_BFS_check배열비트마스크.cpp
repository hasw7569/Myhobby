#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
char miro[50][50];
bool check[50][50][1<<6];
int x_move[4] = { 1,-1,0,0 };
int y_move[4] = { 0,0,1,-1 };
int res = 100000000;
bool ok(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m && miro[x][y] != '#') return true;
	else return false;
}
int main()
{
	pair<int, int> start;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &miro[i][j]);
			if (miro[i][j] == '0') start = { i,j };
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> bfs;
	bfs.push({ start,{0,0} });
	check[start.first][start.second][0] = 1;
	while (!bfs.empty())
	{
		pair<int, int> curr = bfs.front().first;
		int cost = bfs.front().second.first;
		int key = bfs.front().second.second;
		bfs.pop();
		if (miro[curr.first][curr.second] == '1')
		{
			res = min(res, cost);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = { curr.first + x_move[i],curr.second + y_move[i] };
			if (ok(next.first, next.second) && !check[next.first][next.second][key])
			{
				if ((miro[next.first][next.second] >= 'A'&&miro[next.first][next.second] <= 'Z') && !((1 << (miro[next.first][next.second]-'A')) & key)) continue;
				if (miro[next.first][next.second] >= 'a' && miro[next.first][next.second] <= 'z')
				{
					int new_key = key | (1 << (miro[next.first][next.second] - 'a'));
					check[next.first][next.second][new_key] = 1;
					bfs.push({ next,{ cost + 1,new_key } });
				}
				else
				{
					check[next.first][next.second][key] = 1;
					bfs.push({ next,{cost + 1,key} });
				}
			}
		}
	}
	if (res != 100000000)
		printf("%d\n", res);
	else
		printf("-1\n");

	return 0;
}