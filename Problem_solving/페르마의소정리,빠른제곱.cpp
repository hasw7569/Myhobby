#include<stdio.h>
#define DIV 1000000007
int n, m;
long long func(long long x, long long y)
{
	if (!y) return 1;
	if (y % 2)
		return (x*func(x, y - 1)) % DIV;
	return	(func((x*x) % DIV, y / 2)) % DIV;
}
int main()
{
	scanf("%d %d", &n, &m);
	// nCm 이므로
	// (n! / (n-m)! * m!) % div 인데 DIV가 소수이므로
	// 페르마의 소정리 이용 (a^p-1 % p 는 1과 동치)
	// ((n! / (n-m)! * m!) * 1) % div 라고 생각하면
	// ((n! / (n-m)! * m!) * ((n-m)!*m!)^p-1)%DIV
	// 결국 (n! * ((n-m)!*m!)^p-2) % DIV 와 같다
	long long a = 1;
	long long b = 1;
	for (int i = n; i >= 1; i--)
	{
		a *= i;
		a %= DIV;
	}
	for (int i = n - m; i >= 1; i--)
	{
		b *= i;
		b %= DIV;
	}
	for (int i = m; i >= 1; i--)
	{
		b *= i;
		b %= DIV;
	}
	printf("%lld\n", ((a%DIV)*(func(b, DIV - 2) % DIV)) % DIV);
	

	return 0;
}