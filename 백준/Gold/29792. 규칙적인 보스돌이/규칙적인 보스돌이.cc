#define _CRT_SECURE_NO_WARNINGS
#define DMAX 900
#define MAX 49
#define INF 67108863
#define MOD 123456789

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int N, M, K;
long long arr[MAX];
pair<long long, long long> barr[MAX];
vector<int> res;
int dp[DMAX+1];
int ssalmuk = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", " r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<int>());
	for (int i = 0; i < K; i++) {
		long long p, q;
		cin >> p >> q;
		barr[i] = { p, q };
	}

	// 쌀먹 캐릭터
	for (int i = 0; i < N; i++) {
		long long damage = arr[i];

		// 보스
		for (int j = 0; j < K; j++) {
			long long hp = barr[j].first;
			long long deal_time = ceil(1.0 * hp / damage);
			if (deal_time > DMAX) {
				continue;
			}
			int meso = barr[j].second;

			// DP 순환
			for (int k = DMAX - 1; k > 0; k--) {
				if (!dp[k]) {
					continue;
				}
				if (k + deal_time > DMAX) {
					continue;
				}

				dp[k + deal_time] = max(dp[k] + meso, dp[k + deal_time]);
			}

			dp[deal_time] = max(meso, dp[deal_time]);
		}

		int maximum = -1;
		for (int j = 1; j <= DMAX; j++) {
			maximum = max(maximum, dp[j]);
			dp[j] = 0;
		}
		res.push_back(maximum);
	}

	sort(res.begin(), res.end(), greater<int>());
	for (int i = 0; i < M; i++) {
		ssalmuk += res[i];
	}

	cout << ssalmuk;
	return 0;
}
