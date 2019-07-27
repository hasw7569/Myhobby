#include<stdio.h>
#include<utility>
#include<list>
#include<algorithm>
using namespace std;
int x_move[8] = {0,-1,1,-1,1,0,-1,1};
int y_move[8] = {-1,-1,-1,0,0,1,1,1};
int N, M, K;
pair<int,int> graph[12][12];
int A[12][12];
list<pair<int, pair<int, int>>> li[2];
bool ok(int x, int y)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N)
		return true;
	return false;
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &A[i][j]);
			graph[i][j].first = 5;
		}
	}
	
	pair<int, pair<int, int>> input[105];
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &input[i].second.first, &input[i].second.second, &input[i].first);
	}

	sort(input, input + M);

	for (int i = 0; i < M; i++)
	{
		li[0].push_back({ input[i].first,{input[i].second.first,input[i].second.second} }); // �����ؼ� ����Ʈ�� insert
	}

	int st = 0;
	pair<int, pair<int, int>> temp;
	while (K--)
	{
		while (!li[st].empty())
		{
			temp = li[st].front();
			li[st].pop_front();
			if (graph[temp.second.first][temp.second.second].first >= temp.first)
			{
				graph[temp.second.first][temp.second.second].first -= temp.first; // ��� ���Ƹ���
				li[(st+1)%2].push_back({ temp.first+1,{temp.second.first,temp.second.second} }); // ���� ����

				if ((temp.first + 1) % 5 == 0) // 5�� ����� �����ϴ� ���
				{
					for (int i = 0; i < 8; i++)
					{
						if (ok(temp.second.first + x_move[i], temp.second.second + y_move[i]))
						{
							li[(st + 1) % 2].push_front({ 1,{ temp.second.first + x_move[i], temp.second.second + y_move[i] } });
						}
					}
				}
			}
			else
			{
				graph[temp.second.first][temp.second.second].second += (temp.first / 2); // ��� �߰�
			}
			// ��, ����, ���� ó��
		}

		st = (st + 1) % 2;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				graph[i][j].first += graph[i][j].second;
				graph[i][j].second = 0;
				graph[i][j].first += A[i][j];
			}
		}
		// �ܿ�
	}
	printf("%d\n", li[st].size());

	return 0;
}