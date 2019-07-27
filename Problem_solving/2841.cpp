#include<stdio.h>
#include<queue>
using namespace std;
int n,p;
priority_queue<int> pq[7];
int main()
{
	scanf("%d %d", &n, &p);
	int cnt = 0;
	int line, flat;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &line, &flat);
		if (pq[line].empty())
		{
			pq[line].push(flat);
			cnt++;
		}
		else
		{
			if (pq[line].top() < flat)
			{
				pq[line].push(flat);
				cnt++;
			}
			else
			{
				// ������ ū ���鸸 ���ָ�ȴ�
				while (pq[line].top() > flat)
				{
					cnt++;
					pq[line].pop();
					if (pq[line].empty()) break;
				}
				if (pq[line].empty())
				{
					cnt++;
					pq[line].push(flat);
				}
				else
				{
					if (pq[line].top() != flat)
					{
						// ���� ������ �־��� ���� �����Ƿ�
						cnt++;
						pq[line].push(flat);
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}