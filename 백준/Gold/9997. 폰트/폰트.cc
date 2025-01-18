#define _CRT_SECURE_NO_WARNINGS
#define SMAX 25
#define CMAX 26
#define MAX 40000000
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

int N;
int arr[SMAX];
int dp[MAX];
int darr[SMAX] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216 };
int carr[CMAX] = { 33554432, 16777216, 8388608, 4194304, 2097152, 1048576, 524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1 };
int sum = 0;
int sarr[CMAX] = { 0, };

// 비트마스킹
// dp
// 백트래킹


int bitMasking(int lvalue, int rvalue) {
	int ret = 0;
	for (int i = 0; i < CMAX; i++) {
		int l = lvalue / carr[i];
		int r = rvalue / carr[i];

		if (l || r) {
			ret += carr[i];
		}

		lvalue %= carr[i];
		rvalue %= carr[i];
	}

	return ret;
}

int dfs(int idx, int cnt) {
	if (cnt == INF) {
		return pow(2, N - idx);
	}

	if (idx == N) {
		if (cnt == INF) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int cnt1 = bitMasking(arr[idx], cnt);	// idx번째 포함
	int cnt2 = cnt;							// idx번째 미포함

	return dfs(idx + 1, cnt1) + dfs(idx + 1, cnt2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", " r", stdin);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int tarr[CMAX] = { 0, };
		int len = s.length();
		for (int j = 0; j < len; j++) {
			int idx = s[j] - 'a';
			if (tarr[idx]) {
				continue;
			}
			arr[i] += carr[idx];
			tarr[idx]++;

			if (sarr[idx]) {
				continue;
			}
			sum += carr[idx];
			sarr[idx]++;
		}
	}

	if (sum == INF) {
		cout << dfs(0, 0);
	}
	else {
		cout << 0;
	}

	
	return 0;
}

