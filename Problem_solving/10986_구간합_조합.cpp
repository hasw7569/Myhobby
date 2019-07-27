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

	���� 1~a, 1~b ��� ������ �������� ���ٸ�
	a+1~b ��� ������ �������� 0�� �ǰԵȴ�. (a<b �ΰ��)
	���������� �˼� �ִµ�, 1~a ��� ������ 1~b �����ȿ� ���Ѵٸ� 1~a ������ �������� 1~b ������ �״�� �������� �ȴ�.
	�׷��� �� �������� ���ֹ�����
	�� 1~a ������ ���� ������ a+1~b ������ ���ԵǸ� �������� �ڿ������� 0�̵ȴ�.
	|===============| (1~b ����)
	|======| (1~a����) 

	*/

	// nCr �� ���� �� �ִ�.
	// ���� �������� ������ ���� 2���� ������ �ǹǷ� nC2
	for (int i = 0; i < m; i++)
	{
		res += ((remainder[i] * (remainder[i] - 1)) / 2);
	}
	printf("%lld\n", res);
	return 0;
}