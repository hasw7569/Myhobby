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
		if (vt.size() == 0) vt.push_back(val[i]); // ó���� ���
		else
		{
			int idx = lower_bound(vt.begin(), vt.end(), val[i]) - vt.begin();
			if (idx < vt.size()) 
				vt[idx] = val[i];// ���Ϳ� ����ִ� ���ҵ��� �ڱ⺸�� ũ�ų� ���� ������ ���� ���� �� ��, ������ ��ġ�� ����.
			else// �̷��� �������ν� ���� ���ҵ��� ���ö� �� �� LIS�� ���� �� �� �ֵ��� ���ش�.
				vt.push_back(val[i]);// ���� ���Ϳ� ����ִ� ���ҵ麸�� ���� ũ�ٸ� �ǵڿ� �߰�
		}
	}
	printf("%d\n", vt.size());
	// �������� ���Ϳ� ����ִ� ���ҵ��� LIS �����ʹ� ����
	return 0;
}