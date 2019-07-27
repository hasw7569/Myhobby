#include<stdio.h>
int par[200010];
int origin[200010];
int query_1[400010];
int query_2[400010];
bool ans[400010];
int find(int A)
{
	if (par[A] == A)
	{
		return A;
	}
	return par[A] = find(par[A]);
}
void merge(int A, int B)
{
	A = find(A);
	B = find(B);
	if (A == B) return;
	par[A] = B;
}
int N, M;
int main()
{
	scanf("%d %d", &N, &M);
	// N-1개의 EDGE가 주어지고 밑에서 또 N-1개의 EDGE를 끊는다.
	for (int i = 2; i <= N; i++)
	{
		par[i] = i;
		scanf("%d", &origin[i]);
	}
	int x;
	for (int i = 1; i <= (N - 1) + M; i++)
	{
		scanf("%d", &x);
		if (x == 0)
		{
			scanf("%d", &query_1[i]);
		}
		else
		{
			scanf("%d %d", &query_1[i], &query_2[i]);
		}
	}
	for (int i = (N-1)+M; i >= 1; i--)
	{
		if (query_2[i])
		{
			if (find(query_1[i]) == find(query_2[i])) ans[i] = 1;
			else ans[i] = 0;
		}
		else
		{
			merge(query_1[i], origin[query_1[i]]);
		}
	}
	for (int i = 1; i <= (N - 1) + M; i++)
	{
		if (query_2[i])
		{
			if (ans[i]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}