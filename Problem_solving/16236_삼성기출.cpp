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
		graph[shark.first][shark.second] = 0; // ��� ��ġ 0���� �ٲ��ش�
		memset(check, 0, sizeof(check));
		queue<pair<pair<int, int>, int>> bfs; // bfs�� ���� ť
		priority_queue<pair<int, pair<int, int>>> ans; // ���� �� �ִ� ������ ����
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
				ans.push({ -time,{-curr.first,-curr.second} }); // ������ �ִ� ��� ���� ���ǿ� �´� ������ ���ĵǰ� �ִ´�
			}
			for (int i = 0; i < 4; i++)
			{
				if (ok(curr.first + x_move[i], curr.second + y_move[i]))
				{
					bfs.push({ {curr.first + x_move[i],curr.second + y_move[i]},time + 1 }); // bfs ����
				}
			}
		}
		if (ans.empty()) break; // ���� �� �ִ� ����� ���� ��� �����ҷ�
		res -= ans.top().first; // ���� ����� ����� �Դµ� �ɸ��� �ð�
		pair<int, int> curr = ans.top().second; // ����� ��ġ (������ ��� ��ġ)
		curr.first *= -1;
		curr.second *= -1;
		shark = curr; // ��� ��ġ ����
		shark_eat++; // �Ѹ��� �Ծ����� ����
		if (shark_eat == shark_weight)
		{
			shark_weight++;
			shark_eat = 0;
		}
	}
	
	printf("%d\n", res);

	return 0;
}