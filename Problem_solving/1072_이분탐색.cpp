#include<stdio.h>
long long x, y, z;
long long solve()
{
	long long low = 1;
	long long high = 2000000000;
	while (low < high)
	{
		long long mid = (low + high) >> 1;
		long long temp = ((y + mid) * 100) / (x + mid);
		if (temp > z)
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return high;
}
int main()
{
	while (scanf("%lld %lld", &x, &y) != EOF)
	{
		z = (y * 100) / x;
		if (z >= 99) printf("-1\n");
		else printf("%lld\n", solve());
	}
	return 0;
}