#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
pair<double, double> input[101];
vector<pair<double,pair<int, int>>> vt;
int par[101];
int find(int a)
{
	if (a == par[a]) return a;
	return par[a] = find(par[a]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	par[a] = b;
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &input[i].first, &input[i].second);
		par[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			vt.push_back({ sqrt(pow(input[i].first - input[j].first, 2) + pow(input[i].second - input[j].second, 2)),{i,j} });
		}
	}
	sort(vt.begin(), vt.end());
	int cnt = 0;
	double res = 0;
	for (int i = 0; i < vt.size(); i++)
	{
		if (merge(vt[i].second.first, vt[i].second.second))
		{
			cnt++;
			res += vt[i].first;
			if (cnt == n - 1) break;
		}
	}
	printf("%.2lf", res);
	return 0;
}