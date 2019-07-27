#include<stdio.h>
#include<math.h>
int N;
bool func(int A, int B)
{
	bool check[10] = { 0 };
	while (A / 10)
	{
		if (check[A % 10]) return false;
		check[A % 10] = 1;
		A /= 10;
	}
	if (check[A]) return false;
	check[A] = 1;
	while (B / 10)
	{
		if (check[B % 10]) return false;
		check[B % 10] = 1;
		B /= 10;
	}
	if (check[B]) return false;
	check[B] = 1;

	return true;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i < 100000 && i < N; i++)
	{
		if (func(N - i, i))
		{
			printf("%d + %d\n", N - i, i);
			return 0;
		}
	}
	printf("-1\n");

	return 0;
}