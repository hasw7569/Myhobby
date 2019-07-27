#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, l;
int arr[100];
bool solve(int dist)
{
	int cnt = 0;
	for (int i = 0; i < n-1; i++)
	{
		int temp = arr[i];
		while (arr[i + 1] - temp > dist)
		{
			cnt++;
			temp += dist;
		}
	}
	int src = 0;
	int dest = arr[n - 1];
	while (src + dist < arr[0])
	{
		cnt++;
		src += dist;
	}
	while (dest + dist < l)
	{
		cnt++;
		dest += dist;
	}
	if (cnt <= m) return true;
	return false;
}
int main()
{
	scanf("%d %d %d", &n, &m, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int low = 1;
	int high = 1000;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (solve(mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	printf("%d\n", high);
	return 0;
}