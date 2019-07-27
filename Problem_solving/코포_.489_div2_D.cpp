// Max Segment Size
// Minimum Value of P not containg 1 n, 2^n
// Max S , 1e8*n
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll MAX = 2e18; // 2 * 10�� 18��
int main() {
	ll n, k, ans = 0;
	cin >> n >> k;
	vector<ll> v(n);
	for (int i = 0; i<n; i++) cin >> v[i];
	vector<int> countNotOne(n + 1, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		if (v[i] == 1) countNotOne[i] = countNotOne[i + 1] + 1; // �� �տ� �����ϴ� 1�� ����
		else countNotOne[i] = 0;
	}

	for (int s = 0; s<n; s++) {
		ll S = 0, P = 1;
		for (int e = s; e<n; e++) {
			if (countNotOne[e] != 0) {
				ll nS = S + countNotOne[e];
				if (P > k*S && P <= k * nS && P%k == 0) // �� ���� �����ϸ� e~ e+countNotOne[e] �ε����� �ϳ��� �����Ѵٴ� ��� �̹Ƿ�
					ans++;
				S = nS;
				e += countNotOne[e];
				e--; // 1�� ������ �ڱ� �ڽ� �����̰� ������ ���� ���鼭 e�� �ϳ� �� ������ ���̹Ƿ� 1�� ����
				continue;
			}
			S += v[e];
			if (P > MAX/v[e])break; // sum�� �ִ��� 2e5 * e8 �̹Ƿ� // P*v[e] > MAX �� �����ϸ� Ʋ���ٰ� �ߴ� .. P > MAX/v[e]�� ��������
			// �� ��� k�� �ִ��� e5�� ���÷���
			// P�� �ִ��� 2e18�� �ȴ�.
			// ���� 2e18���� �Ѿ�� ��� k�� ������ �Ѿ�� �ǹǷ� �翬�� ���� �ƴϰԵȴ�.
			// �� ��� break�� ���� ������ �ٿ��ش�.
			P *= v[e];
			if (P == k * S) ans++;
		}
	}
		cout << ans;
		return 0;
}