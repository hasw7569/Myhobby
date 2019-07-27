#include<iostream>
#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
pair<int, int> house[2510];
pair<int, int> chicken[15];
int house_cnt, chicken_cnt;
int res = 987654321;
bool check[15];
int N, M;
void solve(int curr, int cnt)
{
	if (curr == chicken_cnt)
	{
		if (cnt > M) return;
		int sum = 0;
		for (int i = 0; i < house_cnt; i++)
		{
			int min_val = 50000;
			for (int j = 0; j < chicken_cnt; j++)
			{
				if(check[j])
					min_val = min(min_val, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
			}
			sum += min_val;
		}
		res = min(res, sum);
	}
	else
	{
		check[curr] = 1; // 선택함
		solve(curr + 1, cnt+1);
		check[curr] = 0; // 선택안함
		solve(curr + 1, cnt);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	int val;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &val);
			if (val == 1)
			{
				// 집
				house[house_cnt++] = { i,j };
			}
			else if (val == 2)
			{
				// 치킨집
				chicken[chicken_cnt++] = { i,j };
			}
		}
	}

	solve(0, 0);
	printf("%d\n", res);


	return 0;
}