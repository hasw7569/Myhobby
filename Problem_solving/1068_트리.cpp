#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<int>> vt;
int N;
vector<int> root;
int cnt;
int erase;
int dfs(int curr)
{
	if (vt[curr].size() == 0)
	{
		return 1;
	}
	else
	{
		int ret = 0;
		for (int i = 0; i < vt[curr].size(); i++)
		{
			if (vt[curr][i] == erase)
			{
				if (vt[curr].size() == 1) ret += 1;
				continue;
			}
			ret += dfs(vt[curr][i]);
		}
		return ret;
	}
}
int main()
{
	scanf("%d", &N);
	vt.resize(N + 1);
	int par;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &par);
		if (par == -1) root.push_back(i);
		else vt[par].push_back(i);
	}
	scanf("%d", &erase);
	for (int i = 0; i < root.size(); i++)
	{
		if(root[i] != erase)
		cnt += dfs(root[i]);
	}
	printf("%d\n", cnt);

	return 0;
}