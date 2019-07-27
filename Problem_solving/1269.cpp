#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> V_A, V_B;
int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int val;
	for (int i = 0; i < A; i++)
	{
		scanf("%d", &val);
		V_A.push_back(val);
	}
	for (int i = 0; i < B; i++)
	{
		scanf("%d", &val);
		V_B.push_back(val);
	}
	sort(V_A.begin(), V_A.end());
	sort(V_B.begin(), V_B.end());
	int ans = 0;
	for (int i = 0; i < V_A.size(); i++)
	{
		if (!binary_search(V_B.begin(), V_B.end(), V_A[i]))
			ans++;
	}
	for (int i = 0; i < V_B.size(); i++)
	{
		if (!binary_search(V_A.begin(), V_A.end(), V_B[i]))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}