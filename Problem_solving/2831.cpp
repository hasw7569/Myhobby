#include<stdio.h>
int n;
long long bit[21][2];
int main()
{
	scanf("%d", &n);
	int person;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &person);
		for (int j = 0; j <= 20; j++)
		{
			if (person & (1 << j)) bit[j][1]++;
			else bit[j][0]++;
		}
	}
	long long res = 0;
	for (int i = 0; i <= 20; i++)
	{
		res += (1 << i) * bit[i][0] * bit[i][1];
	}
	printf("%lld\n", res);

	return 0;
}