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
ll MAX = 2e18; // 2 * 10의 18승
int main() {
	ll n, k, ans = 0;
	cin >> n >> k;
	vector<ll> v(n);
	for (int i = 0; i<n; i++) cin >> v[i];
	vector<int> countNotOne(n + 1, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		if (v[i] == 1) countNotOne[i] = countNotOne[i + 1] + 1; // 내 앞에 존재하는 1의 갯수
		else countNotOne[i] = 0;
	}

	for (int s = 0; s<n; s++) {
		ll S = 0, P = 1;
		for (int e = s; e<n; e++) {
			if (countNotOne[e] != 0) {
				ll nS = S + countNotOne[e];
				if (P > k*S && P <= k * nS && P%k == 0) // 이 조건 만족하면 e~ e+countNotOne[e] 인덱스중 하나는 만족한다는 얘기 이므로
					ans++;
				S = nS;
				e += countNotOne[e];
				e--; // 1의 갯수가 자기 자신 포함이고 어차피 포문 돌면서 e는 하나 더 증가할 것이므로 1개 빼줌
				continue;
			}
			S += v[e];
			if (P > MAX/v[e])break; // sum의 최댓값은 2e5 * e8 이므로 // P*v[e] > MAX 로 제출하면 틀리다고 뜨니 .. P > MAX/v[e]로 제출하자
			// 이 경우 k의 최댓값인 e5이 나올려면
			// P의 최댓값은 2e18이 된다.
			// 만약 2e18값이 넘어가는 경우 k의 범위를 넘어가게 되므로 당연히 답이 아니게된다.
			// 이 경우 break를 통해 연산을 줄여준다.
			P *= v[e];
			if (P == k * S) ans++;
		}
	}
		cout << ans;
		return 0;
}