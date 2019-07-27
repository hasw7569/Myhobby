#include<stdio.h>
long long a, r, n, mod;
long long pow(long long A, long long B)
{
	if (B == 0) return 1;
	if (B % 2) return A * pow(A, B - 1) % mod;
	return pow(A*A%mod, B / 2)%mod;
}
int main()
{
	scanf("%lld %lld %lld %lld", &a, &r, &n, &mod);
	long long ans = 0;
	if (n >= 100000)
	{
		long long thousand = 0;
		for (int i = 0; i < 100000; i++)
		{
			thousand += ((a%mod)*(pow(r%mod, i))) % mod;
			thousand %= mod;
		}
		for (int i = 0; i < n / 100000; i++)
		{
			ans += ((pow(r%mod, 100000 * i)) * (thousand%mod)) % mod;
			ans %= mod;
		}
		for (int i = ((n / 100000) * 100000); i < n; i++)
		{
			ans += ((a%mod)*(pow(r%mod, i))) % mod;
			ans %= mod;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			ans += ((a%mod)*(pow(r%mod, i))) % mod;
			ans %= mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}