#include<stdio.h>
#include<utility>
#include<cstring>
#include<queue>
using namespace std;
pair<int, int> head, tail;
int head_direct = 0; // 초기에는 오른쪽
int x_move[4] = { 0, -1, 0, 1};
int y_move[4] = { 1, 0, -1, 0};
// 왼쪽으로 방향전환할떄는 index 1 증가
// 오른쪽으로 방향전환 할때는 index 1 감소
int N, K, L;
int graph[105][105]; // [1~100][1~100] 범위
bool ok(int x, int y)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N && graph[x][y] < 0) // 사과면 -2, 빈칸이면 -1 이므로
		return true;
	return false;
}
int main()
{
	memset(graph, -1, sizeof(graph)); // 빈공간 -1로 표시
	head = { 1,1 };
	tail = head;
	scanf(" %d %d", &N, &K);
	int x, y;
	for (int i = 0; i < K; i++)
	{
		scanf(" %d %d", &x, &y);
		graph[x][y] = -2; // 사과 -2로 표시
	}
	scanf(" %d", &L);
	queue<pair<int, char>> change;
	char z;
	for (int i = 0; i < L; i++)
	{
		scanf(" %d %c", &x, &z);
		change.push({ x,z });
	}
	int time = 0;
	while (1)
	{
		time++; // 시간 증가

		graph[head.first][head.second] = head_direct; // 몸통이 머리의 방향을 보고 따라올 수 있도록 표시해준다.
		if (ok(head.first + x_move[head_direct], head.second + y_move[head_direct]))
		{
			head.first += x_move[head_direct];
			head.second += y_move[head_direct]; // 머리 위치 변경
			if (graph[head.first][head.second] != -2) // 사과를 먹지 못했다면 꼬리도 한칸 이동해준다
			{
				int tail_direct = graph[tail.first][tail.second];
				graph[tail.first][tail.second] = -1; // 빈칸으로 바꿔준다
				tail.first += x_move[tail_direct];
				tail.second += y_move[tail_direct]; // 이미 몸통이 이동했던 방향이므로 범위 체크 안해줘도된다.
			}
		}
		else
		{
			break;
		}

		
		if (!change.empty())
		{
			if (change.front().first == time)
			{
				if (change.front().second == 'L')
				{
					// 왼쪽인경우 index 1 증가
					head_direct += 1;
					head_direct %= 4;
				}
				else
				{
					// 오른쪽인경우 index 1 감소
					head_direct += 3;
					head_direct %= 4;
				}
				change.pop();
			}
		}
	}
	printf("%d\n", time);
	return 0;
}