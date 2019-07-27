#include<stdio.h>
#define MAX_N 1000002

int K, N, Q;
int par[MAX_N];
int par_size[MAX_N];
int club[MAX_N];
int L[MAX_N];
int R[MAX_N];

int find(int a)
{
	if (a == par[a]) return a;
	return par[a] = find(par[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (club[a] == club[b])
	{
		par[a] = b;
		par_size[b] += par_size[a];
		par_size[a] = 0;
	}
}
int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &club[i]);
		L[i] = i - 1;
		R[i] = i + 1;
		par_size[i] = 1;
		par[i] = i;
		if (club[i] == club[i - 1])
		{
			par[i - 1] = i;
			par_size[i] += par_size[i - 1];
			par_size[i - 1] = 0;
		}
	}

	scanf("%d", &Q);
	int a, b;
	long long sum = 0;
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &a, &b);
		int b_par = find(b);
		if (a == 1)
		{
			// b가 퇴출되는 경우
			par_size[b_par]--;
			R[L[b]] = R[b];
			L[R[b]] = L[b];
			if(club[L[b]] == club[R[b]])
				merge(L[b], R[b]);
		}
		else
		{
			sum += par_size[b_par];
		}
	}
	printf("%lld\n", sum);
	return 0;
}