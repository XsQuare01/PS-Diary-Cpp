#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 1000000
#define INF 1000000001

#include<iostream>

using namespace std;

int n;
int n_arr[MAX_N + 2][2];
int ancs_prefix[MAX_N + 2][2];
int desc_prefix[MAX_N + 2][2];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		n_arr[i][0] = u;
		n_arr[i][1] = v;
	}
}

void solve() {
	int _left = INF;
	int _right = 0;
	for (int i = 1; i <= n; i++) {
		if (n_arr[i][0] && _left > n_arr[i][0]) {
			_left = n_arr[i][0];
		}

		if (n_arr[i][1] && _right < n_arr[i][1]) {
			_right = n_arr[i][1];
		}
		ancs_prefix[i][0] = _left;
		ancs_prefix[i][1] = _right;
	}

	_left = 0;
	_right = INF;
	for (int i = n; i >= 1; i--) {
		if (n_arr[i][0] && _left < n_arr[i][0]) {
			_left = n_arr[i][0];
		}

		if (n_arr[i][1] && _right > n_arr[i][1]) {
			_right = n_arr[i][1];
		}
		
		desc_prefix[i][0] = _left;
		desc_prefix[i][1] = _right;
	}

	int cnt = 0;
	for (int i = n-1; i >= 1; i--) {
		if ((ancs_prefix[i][0] > desc_prefix[i + 1][0]) && (ancs_prefix[i][1] < desc_prefix[i + 1][1])) {
			cnt = i;
			break;
			
		}
	}
	if (!cnt) {
		cnt = -1;
	}
	cout << cnt;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solve();

	return 0;
}