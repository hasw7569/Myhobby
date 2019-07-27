#include<stdio.h>
#include<algorithm>
using namespace std;
long long N, K, Q;
long long x, y;
long long x_depth, y_depth;
long long res;
long long find_depth(long long val)
{
	for (int i = 1; ; i++)
	{
		val += (K - 2);
		val /= K;
		if (!val) return i;
	}
}
int main()
{
	scanf("%lld %lld %lld", &N, &K, &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%lld %lld", &x, &y);
		if (K == 1)
		{
			printf("%lld\n", max(x, y) - min(x, y));
			continue;
		}
		// K��Ʈ���϶� x,y ���� K-2 �� ���ؼ� K�� ������ �θ��� ��ȣ�� ���´�.
		// ���̴� ? 1 -> 1 + K -> 1 + K + K^2 ... ������ �þ�Ƿ�
		// (K^n - 1) / (K - 1) ���� �̿��ؼ� ���̸� ã�� �� �ִ�.
		// ���̸� ã�� �� ���� ���̸� �����ϰ� ����� �ְ�, ���� ����� �θ� ã����ȴ�.
		x_depth = find_depth(x);
		y_depth = find_depth(y);
		res = 0;
		if (x_depth < y_depth)
		{
			res = y_depth - x_depth;
			for (int j = 0; j < res; j++)
			{
				y += (K - 2);
				y /= K;
			}
		}
		else if (x_depth > y_depth)
		{
			res = x_depth - y_depth;
			for (int j = 0; j < res; j++)
			{
				x += (K - 2);
				x /= K;
			}
		}
		if (x == y) printf("%lld\n", res);
		else
		{
			while (x != y)
			{
				x += (K - 2);
				x /= K;
				y += (K - 2);
				y /= K;
				res += 2;
			}
			printf("%lld\n",res);
		}
	}


	return 0;
}