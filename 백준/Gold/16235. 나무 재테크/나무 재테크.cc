#define _CRT_SECURE_NO_WARNINGS
#define FMAX 5000000
#define MAX 10
#define DMAX 300000
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
int arr[MAX][MAX];
vector<int> tree[MAX][MAX];
int soil[MAX][MAX];
priority_queue<int, vector<int>, greater<int>> pq[MAX][MAX];
int darr[][2] = {
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, 1},
	{0, -1},
	{1, 1},
	{1, 0},
	{1, -1}
};

inline bool inBoundary(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < N;
}

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			while (!pq[i][j].empty()) {
				int t = pq[i][j].top();
				if (soil[i][j] < t) {
					break;
				}

				pq[i][j].pop();
				tree[i][j].push_back(t+1);
				soil[i][j] -= t;
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			while (!pq[i][j].empty()) {
				int t = pq[i][j].top();
				pq[i][j].pop();

				soil[i][j] += (t / 2);
			}
		}
	}
}

void autumn() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (auto a : tree[i][j]) {
				if (a % 5) {
					continue;
				}

				for (auto [dy, dx] : darr) {
					int ty = i + dy;
					int tx = j + dx;

					if (!inBoundary(ty, tx)) {
						continue;
					}

					tree[ty][tx].push_back(1);
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			soil[i][j] += arr[i][j];
			for (auto a : tree[i][j]) {
				pq[i][j].push(a);
			}

			tree[i][j] = vector<int>();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", " r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			soil[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> y >> x >> z;
		x -= 1;
		y -= 1;
		pq[y][x].push(z);
	}

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		autumn();
		winter();
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res += pq[i][j].size();
		}
	}
	cout << res;


	return 0;
}
