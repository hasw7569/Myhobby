#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;
int graph[21][21];
bool check[21][21];
pair<int, int> shark;
int shark_weight = 2;
int shark_eat = 0;
int N;
int x_move[4] = { 1,-1,0,0 };
int y_move[4] = { 0,0,1,-1 };
bool ok(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N && !check[x][y] && graph[x][y] <= shark_weight)
		return true;
	return false;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 9)
				shark = { i,j };
		}
	}
	int res = 0;
	while (1)
	{
		graph[shark.first][shark.second] = 0; // 상어 위치 0으로 바꿔준다
		memset(check, 0, sizeof(check));
		queue<pair<pair<int, int>, int>> bfs; // bfs를 위한 큐
		priority_queue<pair<int, pair<int, int>>> ans; // 먹을 수 있는 물고기들 저장
		bfs.push({ shark,0 });
		while (!bfs.empty())
		{
			pair<int, int> curr = bfs.front().first;
			int time = bfs.front().second;
			bfs.pop();
			if (check[curr.first][curr.second]) continue;
			check[curr.first][curr.second] = 1;
			if (graph[curr.first][curr.second] > 0 && graph[curr.first][curr.second] < shark_weight)
			{
				ans.push({ -time,{-curr.first,-curr.second} }); // 먹을수 있는 경우 문제 조건에 맞는 순서로 정렬되게 넣는다
			}
			for (int i = 0; i < 4; i++)
			{
				if (ok(curr.first + x_move[i], curr.second + y_move[i]))
				{
					bfs.push({ {curr.first + x_move[i],curr.second + y_move[i]},time + 1 }); // bfs 수행
				}
			}
		}
		if (ans.empty()) break; // 먹을 수 있는 물고기 없는 경우 엄마불러
		res -= ans.top().first; // 가장 가까운 물고기 먹는데 걸리는 시간
		pair<int, int> curr = ans.top().second; // 물고기 위치 (다음번 상어 위치)
		curr.first *= -1;
		curr.second *= -1;
		shark = curr; // 상어 위치 변경
		shark_eat++; // 한마리 먹었으니 갱신
		if (shark_eat == shark_weight)
		{
			shark_weight++;
			shark_eat = 0;
		}
	}
	
	printf("%d\n", res);

	return 0;
}