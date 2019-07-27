#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
int a, b, c;
int par[1001];
vector<pair<int, pair<int, int>>> vt1, vt2;
int find(int a)
{
	if (par[a] == -1) return a;
	return par[a] = find(par[a]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == -1 && b == -1 || a != b)
	{
		par[a] = b;
		return true;
	}
	return false;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m+1; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		vt1.push_back({ -c,{ a,b } });
		vt2.push_back({ c,{ a,b } });
	}
	sort(vt1.begin(), vt1.end());
	sort(vt2.begin(), vt2.end());
	memset(par, -1, sizeof(par));
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < vt1.size(); i++)
	{
		if (merge(vt1[i].second.first, vt1[i].second.second))
		{
			if (vt1[i].first == 0) sum1++;
		}
	}
	memset(par, -1, sizeof(par));
	for (int i = 0; i < vt2.size(); i++)
	{
		if (merge(vt2[i].second.first, vt2[i].second.second))
		{
			if (vt2[i].first == 0) sum2++;
		}
	}

	sum1 *= sum1;
	sum2 *= sum2;
	printf("%d\n", sum2 - sum1);
	return 0;
}