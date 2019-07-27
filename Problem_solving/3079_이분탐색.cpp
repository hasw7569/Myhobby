#include<stdio.h>
long long n, m;
long long T[100001];
int main()
{
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &T[i]);
	}
	long long low = 1;
	long long high = 1e16;
	while (low < high)
	{
		long long mid = (low + high) >> 1;
		long long pass = 0;
		for (int i = 0; i < n; i++)
		{
			pass += mid / T[i];
		}
		if (pass >= m) high = mid;
		else low = mid + 1;
	}
	printf("%lld\n", high);
	return 0;
}