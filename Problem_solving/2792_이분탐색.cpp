#include<stdio.h>
long long n, m;
long long jual[300000];
long long sum;
bool solve(long long val)
{
	long long cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cnt += (jual[i] / val);
		cnt += (jual[i] % val != 0 ? 1 : 0);
	}
	if (cnt <= n) return true;
	return false;
}
int main()
{
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &jual[i]);
		sum += jual[i];
	}
	long long low = 1;
	long long high = sum;
	high *= m;
	while (low < high)
	{
		long long mid = (low + high) >> 1;
		if (solve(mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	printf("%lld\n", high);
	return 0;
}