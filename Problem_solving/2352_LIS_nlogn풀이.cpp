#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int val[40001];
vector<int> vt;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vt.size() == 0) vt.push_back(val[i]); // 처음의 경우
		else
		{
			int idx = lower_bound(vt.begin(), vt.end(), val[i]) - vt.begin();
			if (idx < vt.size()) 
				vt[idx] = val[i];// 벡터에 들어있는 원소들중 자기보다 크거나 같은 원소중 가장 작은 값 즉, 최적의 위치에 들어간다.
			else// 이렇게 해줌으로써 다음 원소들이 들어올때 더 긴 LIS를 구성 할 수 있도록 해준다.
				vt.push_back(val[i]);// 만약 벡터에 들어있는 원소들보다 값이 크다면 맨뒤에 추가
		}
	}
	printf("%d\n", vt.size());
	// 마지막에 벡터에 들어있는 원소들은 LIS 순서와는 무관
	return 0;
}