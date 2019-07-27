#include<stdio.h>
#include<algorithm>
using namespace std;
int val[1001];
int dp[1001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (val[j] > val[i]) dp[j] = max(dp[j], dp[i] + 1);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (val[j] < val[i]) dp[j] = max(dp[j], dp[i] + 1);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}