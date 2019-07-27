#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
bool matrix[1000][1000];
int Size[1000][1000];
int n, m;
int x_move[3] = { 0,-1,-1 };
int y_move[3] = {-1,0,-1 };
bool ok(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y]) return true;
	return false;
}
int main()
{
	int res = 0;
	scanf("%d %d", &n, &m);
	char input;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &input);
			matrix[i][j] = input - '0';
			if (matrix[i][j]) Size[i][j] = 1;
			res = max(res, Size[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!matrix[i][j]) continue;

			bool flag = 1;
			int min_val = 1e9;
			for (int k = 0; k < 3; k++)
			{
				if (!ok(i + x_move[k], j + y_move[k]))
				{
					flag = 0;
					break;
				}
				min_val = min(min_val, Size[i + x_move[k]][j + y_move[k]]);
			}
			if (flag)
			{
				Size[i][j] += min_val * 3;
				Size[i][j] -= (min_val - sqrt(min_val))*2;
				res = max(res, Size[i][j]);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}