#include<iostream>
#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;
int x_move[4] = { 0,-1,0,1 };
int y_move[4] = { 1,0,-1,0 };
int graph[101][101];
int main()
{
	int N;
	int x, y, d, g;
	pair<int, int> Start;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &y, &x, &d, &g); // x, y 반대로 잡았음 입력 반대로 받는다.
		Start = { x + x_move[d], y + y_move[d] }; // 시작 위치 잡아준다.
		queue<pair<int, int>> Que;
		Que.push({ x,y });
		Que.push(Start);
		for (int j = 0; j < g; j++) // 세대수 만큼 반복
		{
			int size = Que.size(); // 현재 세대에서의 좌표 갯수
			while (size--)
			{
				pair<int, int> curr = Que.front();
				Que.pop();
				Que.push(curr); // 다시 넣어주는거 잊으면 안된다.

				if (curr == Start) continue;// 기준점은 바뀌지 않으므로
				// 기준x좌표에 y차 만큼 더해주고 기준 y좌표에 x 차 만큼 빼준다
				int next_x = curr.second - Start.second;
				int next_y = curr.first - Start.first;

				Que.push({ Start.first + next_x, Start.second - next_y }); // 격자 밖으로 벗어나지 않는다고 문제에서 명시
				// 벗어난다면 별개의 처리를 해주어야한다.
			}
			// Start 위치 바꿔준다 (x,y) 위치 가지고
			int next_x = y - Start.second;
			int next_y = x - Start.first;
			Start.first = Start.first + next_x;
			Start.second = Start.second - next_y;
		}
		while (!Que.empty())
		{
			pair<int, int> curr = Que.front();
			Que.pop();
			graph[curr.first][curr.second] = 1;
		}
	}

	int res = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			// [0~99][0~99] 사이에서 정사각형 찾는다.
			if (graph[i][j] && graph[i + 1][j] && graph[i + 1][j + 1] && graph[i][j + 1]) res++;
		}
	}
	printf("%d\n", res);

	return 0;
}