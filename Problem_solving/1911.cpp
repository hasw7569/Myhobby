#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> vt;
int n, l;
int main()
{
	scanf("%d %d", &n, &l);
	pair<int, int> hole;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &hole.first, &hole.second);
		vt.push_back(hole);
	}
	sort(vt.begin(), vt.end());
	int res = 0;
	int last = 0;
	for (int i = 0; i < vt.size(); i++)
	{
		int st = vt[i].first > last ? vt[i].first : last + 1;
		int dest = vt[i].second-1;
		if (st > dest) continue;
		if ((dest - st + 1) % l)
		{
			last = st + ((dest - st + 1) / l)*l + l - 1;
			res += ((dest - st + 1) / l) + 1;
		}
		else
		{
			last = st + ((dest - st + 1) / l)*l - 1;
			res += ((dest - st + 1) / l);
		}
	}
	printf("%d\n", res);
	return 0;
}