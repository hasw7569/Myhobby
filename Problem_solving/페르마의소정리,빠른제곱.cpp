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
	// nCm �̹Ƿ�
	// (n! / (n-m)! * m!) % div �ε� DIV�� �Ҽ��̹Ƿ�
	// �丣���� ������ �̿� (a^p-1 % p �� 1�� ��ġ)
	// ((n! / (n-m)! * m!) * 1) % div ��� �����ϸ�
	// ((n! / (n-m)! * m!) * ((n-m)!*m!)^p-1)%DIV
	// �ᱹ (n! * ((n-m)!*m!)^p-2) % DIV �� ����
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