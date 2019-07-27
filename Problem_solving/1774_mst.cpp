#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
int N, M;
pair<double,double> pos[1001];
vector<pair<double, pair<int,int>>> vt;
int par[1001];
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
	double res = 0;
	int cnt = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lf %lf", &pos[i].first, &pos[i].second);
		par[i] = i;
	}
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		if (merge(a, b))
		{
			cnt++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			vt.push_back({ sqrt(pow(pos[i].first - pos[j].first,2) + pow(pos[i].second - pos[j].second,2)),{i,j} });
		}
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++)
	{
		if (merge(vt[i].second.first, vt[i].second.second))
		{
			cnt++;
			res += vt[i].first;
			if (cnt == N - 1) break;
		}
	}
	printf("%.2lf", res);
	return 0;
}