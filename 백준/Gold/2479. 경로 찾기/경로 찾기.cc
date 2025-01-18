#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#define KMAX 30
#define INF 987654321
#define MOD 123456789

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};

int N, K, A, B;
int arr[MAX][KMAX];
vector<int> edge[MAX];
bool flag[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
stack<int> st;

// 초기 거리 계산
void setDist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int distance = 0;
			for (int k = 0; k < K; k++) {
				if (arr[i][k] != arr[j][k]) {
					distance++;
				}
			}
			
			if (distance == 1) {
				edge[i].push_back(j);
			}
		}
	}
}

bool DFS(int idx) {
	st.push(idx);
	flag[idx] = true;

	for (auto a : edge[idx]) {
		if (flag[a]) {
			continue;
		}

		if (a == B) {
			st.push(B);
			return true;
		}

		if (DFS(a)) {
			return true;
		}

	}
	flag[idx] = false;
	st.pop();
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", " r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < K; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	cin >> A >> B;
	A -= 1;
	B -= 1;
	setDist();

	DFS(A);

	vector<int> res;
	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}

	reverse(res.begin(), res.end());
	if (res.empty()) {
		cout << -1;
	}
	else {
		for (auto a : res) {
			cout << a + 1 << " ";
		}
	}

	return 0;
}