#include<stdio.h>
#include<utility>
#include<cstring>
#include<queue>
using namespace std;
pair<int, int> head, tail;
int head_direct = 0; // �ʱ⿡�� ������
int x_move[4] = { 0, -1, 0, 1};
int y_move[4] = { 1, 0, -1, 0};
// �������� ������ȯ�ҋ��� index 1 ����
// ���������� ������ȯ �Ҷ��� index 1 ����
int N, K, L;
int graph[105][105]; // [1~100][1~100] ����
bool ok(int x, int y)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N && graph[x][y] < 0) // ����� -2, ��ĭ�̸� -1 �̹Ƿ�
		return true;
	return false;
}
int main()
{
	memset(graph, -1, sizeof(graph)); // ����� -1�� ǥ��
	head = { 1,1 };
	tail = head;
	scanf(" %d %d", &N, &K);
	int x, y;
	for (int i = 0; i < K; i++)
	{
		scanf(" %d %d", &x, &y);
		graph[x][y] = -2; // ��� -2�� ǥ��
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
		time++; // �ð� ����

		graph[head.first][head.second] = head_direct; // ������ �Ӹ��� ������ ���� ����� �� �ֵ��� ǥ�����ش�.
		if (ok(head.first + x_move[head_direct], head.second + y_move[head_direct]))
		{
			head.first += x_move[head_direct];
			head.second += y_move[head_direct]; // �Ӹ� ��ġ ����
			if (graph[head.first][head.second] != -2) // ����� ���� ���ߴٸ� ������ ��ĭ �̵����ش�
			{
				int tail_direct = graph[tail.first][tail.second];
				graph[tail.first][tail.second] = -1; // ��ĭ���� �ٲ��ش�
				tail.first += x_move[tail_direct];
				tail.second += y_move[tail_direct]; // �̹� ������ �̵��ߴ� �����̹Ƿ� ���� üũ �����൵�ȴ�.
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
					// �����ΰ�� index 1 ����
					head_direct += 1;
					head_direct %= 4;
				}
				else
				{
					// �������ΰ�� index 1 ����
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