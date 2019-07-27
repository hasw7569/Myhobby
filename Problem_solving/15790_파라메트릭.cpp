#include<stdio.h>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
vector<int> hole;
int n, m,k;
bool check[1001];
bool para(int leng)
{
	// legn �̻��� ���̷� k���� ������ �����ȴ�.
	// k���� Ȩ�� ������ �ȴ�
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		int st = i;
		int end = hole[i] + n - 1; 
		for (int j = i+1; j < i + m; j++)
		{
			if (hole[j] - hole[st] >= leng)
			{
				st = j;
				cnt++;
			}
		}
		if (st == i) continue;
		if (end - hole[st] >= leng) cnt++; // �������� ���� Ȩ���� ó���� ���� Ȩ ������ ����
		if (cnt >= k) return true;
	}
	return false;
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if (k == 1)
	{
		printf("%d\n", n);
	}
	else
	{
		hole.resize(m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &hole[i]);
		}
		for (int i = 0; i < m; i++)
		{
			hole.push_back(hole[i] + n - 1);
		}
		int low = 1;
		int high = n;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			if (para(mid)) low = mid + 1;
			else high = mid;
		}
		if (low == 1) printf("-1\n");
		else printf("%d\n", low - 1);
	}
	return 0;
}