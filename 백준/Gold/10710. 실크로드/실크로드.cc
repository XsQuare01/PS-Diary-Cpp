#define _CRT_SECURE_NO_WARNINGS
#define DMAX 900
#define MAX 1000
#define INF 987654321
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

int N, M;
int arr[MAX];
int warr[MAX];
int dp[MAX+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", " r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i + 1] = INF;
	}
	for (int i = 0; i < M; i++) {
		cin >> warr[i];
	}

	// 날짜
	for (int i = 0; i < M; i++) {
		int weather = warr[i];

		// 도시 순회
		for (int j = N - 1; j > 0; j--) {
			if (dp[j] == INF) {
				continue;
			}
			int dist = arr[j];
			dp[j + 1] = min(dp[j + 1], dp[j] + dist * weather);
		}

		dp[1] = min(dp[1], arr[0] * weather);
	}

	cout << dp[N];
	return 0;
}
