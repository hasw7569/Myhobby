#include<stdio.h>
int n, m;
int sum;
long long remainder[1001];
int main()
{
	int temp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		sum += temp;
		sum %= m;
		remainder[sum]++;
	}
	long long res = remainder[0];

	/*

	만약 1~a, 1~b 라는 구간의 나머지가 같다면
	a+1~b 라는 구간의 나머지는 0이 되게된다. (a<b 인경우)
	직관적으로 알수 있는데, 1~a 라는 구간이 1~b 구간안에 속한다면 1~a 구간의 나머지를 1~b 구간도 그대로 가져가게 된다.
	그런데 그 나머지를 없애버리면
	즉 1~a 구간을 없애 버리고 a+1~b 구간을 보게되면 나머지가 자연스럽게 0이된다.
	|===============| (1~b 구간)
	|======| (1~a구간) 

	*/

	// nCr 로 구할 수 있다.
	// 같은 나머지를 가지는 구간 2개를 뽑으면 되므로 nC2
	for (int i = 0; i < m; i++)
	{
		res += ((remainder[i] * (remainder[i] - 1)) / 2);
	}
	printf("%lld\n", res);
	return 0;
}