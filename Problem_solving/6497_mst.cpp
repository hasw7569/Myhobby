#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n, m;
ll p[200001];
vector<pair<ll, pair<int, int>>> vt;
ll find(ll a)
{
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}
bool merge(ll a, ll b)
{
	a = find(a);
	b = find(b);
	if ((a == -1 && b == -1) || a != b)
	{
		p[a] = b;
		return true;
	}
	return false;
}
int main()
{
	while (1)
	{
		memset(p, -1, sizeof(p));
		vt.clear();

		scanf("%lld %lld", &n, &m);
		if (n == 0 && m == 0) break;
		ll x, y, z;
		ll sum = 0;

		for (int i = 0; i < m; i++)
		{
			scanf("%lld %lld %lld", &x, &y, &z);
			sum += z;
			vt.push_back({ z,{x,y} });
		}
		sort(vt.begin(), vt.end());

		ll res = 0;
		for (int i = 0; i < vt.size(); i++)
		{
			if (merge(vt[i].second.first, vt[i].second.second)) res += vt[i].first;
		}
		printf("%lld\n", sum - res);
	}
	return 0;
}