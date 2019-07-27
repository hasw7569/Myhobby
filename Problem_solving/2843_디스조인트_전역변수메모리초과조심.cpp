#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;
int N,Q;
int par[300001];
bool erase[300001];
int find(int A)
{
	if (par[A] == A) return A;
	return par[A] = find(par[A]);
}
void merge(int A, int B)
{
	A = find(A);
	B = find(B);
	if (A == B)
	{
		par[A] = 0;
	}
	else
	{
		par[A] = B;
	}
}
int main()
{
	int edge[300001];
	vector<int> res;
	int query[300001][2];
	scanf(" %d", &N);
	for (int i = 0; i <= N; i++) par[i] = i;
	for (int i = 1; i <= N; i++)
	{
		scanf(" %d", &edge[i]);
	}
	scanf(" %d", &Q);

	for (int i = 1; i <= Q; i++)
	{
		scanf("%d %d", &query[i][0], &query[i][1]);
		if (query[i][0] == 2)
		{
			erase[query[i][1]] = 1; // 2번쿼리에 의해 없어질 간선들 체크
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (!erase[i] && edge[i]) merge(i, edge[i]); // 2번쿼리에 영향 안받는 간선들
	}


	for (int i = Q; i >= 1; i--)
	{
		if (query[i][0] == 1)
		{
			res.push_back(find(query[i][1]));
		}
		else
		{
			merge(query[i][1], edge[query[i][1]]);
		}
	}

	while (!res.empty())
	{
		int Q = res.back();
		res.pop_back();
		if(Q == 0)  printf("CIKLUS\n");
		else printf("%d\n", Q);
		
	}
	
	return 0;
}