#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<double, double> PI;
typedef pair<PI, PI> PII;
PII bang[100001];
int n,m;
PI razor;
vector<double> vt;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf %lf %lf", &bang[i].first.first, &bang[i].first.second, &bang[i].second.first, &bang[i].second.second);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%lf %lf", &razor.first, &razor.second);
		vt.push_back(razor.second / razor.first);
	}
	sort(vt.begin(), vt.end());
	// 기울기만 따지면 된다.
	int res = n;
	for (int i = 1; i <= n; i++)
	{
		double s = bang[i].first.second / bang[i].first.first;
		double f = bang[i].second.second / bang[i].second.first;
		if (s > f) swap(s, f);
		// s <= x <= f 인  x가 존재하는지 binary search 하면된다.
		if (lower_bound(vt.begin(), vt.end(), s) != vt.end())
		{
			double comp = *(lower_bound(vt.begin(), vt.end(), s));
			if (s <= comp && comp <= f) res--;
		}
	}
	printf("%d\n", res);

	return 0;
}