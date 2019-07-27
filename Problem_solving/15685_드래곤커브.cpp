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
		scanf("%d %d %d %d", &y, &x, &d, &g); // x, y �ݴ�� ����� �Է� �ݴ�� �޴´�.
		Start = { x + x_move[d], y + y_move[d] }; // ���� ��ġ ����ش�.
		queue<pair<int, int>> Que;
		Que.push({ x,y });
		Que.push(Start);
		for (int j = 0; j < g; j++) // ����� ��ŭ �ݺ�
		{
			int size = Que.size(); // ���� ���뿡���� ��ǥ ����
			while (size--)
			{
				pair<int, int> curr = Que.front();
				Que.pop();
				Que.push(curr); // �ٽ� �־��ִ°� ������ �ȵȴ�.

				if (curr == Start) continue;// �������� �ٲ��� �����Ƿ�
				// ����x��ǥ�� y�� ��ŭ �����ְ� ���� y��ǥ�� x �� ��ŭ ���ش�
				int next_x = curr.second - Start.second;
				int next_y = curr.first - Start.first;

				Que.push({ Start.first + next_x, Start.second - next_y }); // ���� ������ ����� �ʴ´ٰ� �������� ���
				// ����ٸ� ������ ó���� ���־���Ѵ�.
			}
			// Start ��ġ �ٲ��ش� (x,y) ��ġ ������
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
			// [0~99][0~99] ���̿��� ���簢�� ã�´�.
			if (graph[i][j] && graph[i + 1][j] && graph[i + 1][j + 1] && graph[i][j + 1]) res++;
		}
	}
	printf("%d\n", res);

	return 0;
}