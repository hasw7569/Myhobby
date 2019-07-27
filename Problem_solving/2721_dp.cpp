#include<stdio.h>
typedef long long ll;
ll W[301];
int T;
int main()
{
	for (int i = 1; i <= 300; i++)
	{
		W[i] = W[i - 1] + i * (((i + 1)*(i + 2)) / 2);
	}
	scanf("%d", &T);
	int pos;
	while (T--)
	{
		scanf("%d", &pos);
		printf("%lld\n", W[pos]);
	}


	return 0;
}