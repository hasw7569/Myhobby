#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
char graph[50][50];
int x_move[4] = { 0,0,1,-1 };
int y_move[4] = { 1,-1,0,0 };
bool ok(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
	{
		return true;
	}
	return false;
}
int func(int size)
{
	int ret = 0;
	for (int i = 0; i < size; i++)
	{
		int row = 1;
		int col = 1;
		for (int j = 1; j < size; j++)
		{
			if (graph[i][j] == graph[i][j - 1])
			{
				row++;
				ret = max(ret, row);
			}
			else
			{
				row = 1;
				ret = max(ret, row);
			}
			if (graph[j][i] == graph[j - 1][i])
			{
				col++;
				ret = max(ret, col);
			}
			else
			{
				col = 1;
				ret = max(ret, col);
			}
		}
	}
	return ret;
}
int solve(int size)
{
	int ret = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int next_x = i + x_move[k];
				int next_y = j + y_move[k];
				if (ok(next_x, next_y))
				{
					char a = graph[i][j];
					char b = graph[next_x][next_y];
					graph[i][j] = b;
					graph[next_x][next_y] = a;
					ret = max(ret, func(size));
					graph[i][j] = a;
					graph[next_x][next_y] = b;
				}
			}
		}
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf(" %c", &graph[i][j]);
		}
	}

	printf("%d\n", solve(N));
	return 0;
}