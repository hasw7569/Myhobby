#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, M,K;
bool elec[1001];
int par[1001];
vector<pair<int, pair<int, int>>> vt;
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
	if (elec[a] && elec[b]) return false;
	par[a] = b;
	if (elec[a]) elec[b] = true; // 해당 그룹의 root를 계속 업데이트해준다.
	return true;
}
int main()
{
	for (int i = 1; i <= 1000; i++) par[i] = i;
	int u, v, w;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &u);
		elec[u] = true;
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		vt.push_back({ w,{u,v} });
	}
	sort(vt.begin(), vt.end());
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < vt.size(); i++)
	{
		if (merge(vt[i].second.first, vt[i].second.second))
		{
			cnt++;
			res += vt[i].first;
		}
		if (cnt == N - 1) break;
	}
	printf("%d\n", res);

	return 0;
}