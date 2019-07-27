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
		// K진트리일때 x,y 값에 K-2 를 더해서 K로 나누면 부모의 번호가 나온다.
		// 깊이는 ? 1 -> 1 + K -> 1 + K + K^2 ... 순으로 늘어나므로
		// (K^n - 1) / (K - 1) 식을 이용해서 깊이를 찾을 수 있다.
		// 깊이를 찾은 뒤 둘의 깊이를 동일하게 만들어 주고, 가장 가까운 부모를 찾으면된다.
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