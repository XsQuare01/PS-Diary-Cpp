#define _CRT_SECURE_NO_WARNINGS
#define FMAX 5000000
#define MAX 200000
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

int N, Q;
pair<long long, long long> arr[MAX];
// 도착지를 기준으로
double prefix[MAX + 2];
double rprefix[MAX + 2];
double lprefix[MAX + 2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed;
	cout.precision(10);
	//freopen("input.txt", " r", stdin);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr[i].first = x;

	}
	for (int i = 0; i < N; i++) {
		int y;
		cin >> y;
		arr[i].second = y;
	}

	for (int i = 1; i <= N; i++) {
		auto le = arr[i - 1];
		auto ri = arr[i];

		double dist = (le.first - ri.first) * (le.first - ri.first) + (le.second - ri.second) * (le.second - ri.second);
		dist = sqrt(dist);
		prefix[i] = prefix[i - 1] + dist;
	}

	// ->
	for (int i = 1; i < N; i++) {
		auto le = arr[i - 1];
		auto ri = arr[i];
		double dist = prefix[i] - prefix[i - 1];
		if (le.second < ri.second) {
			dist *= 3;
		}
		else if (le.second == ri.second) {
			dist *= 2;
		}

		rprefix[i] = rprefix[i - 1] + dist;
	}

	// <-
	for (int i = N-1; i > 0; i--) {
		auto le = arr[i - 1];
		auto ri = arr[i];

		double dist = prefix[i] - prefix[i - 1];	// N-2 -> N-1
		if (le.second > ri.second) {
			dist *= 3;
		}
		else if (le.second == ri.second) {
			dist *= 2;
		}

		lprefix[i-1] = lprefix[i] + dist;
	}

	for (int i = 0; i < Q; i++) {
		int le, ri;
		cin >> le >> ri;
		le -= 1;
		ri -= 1;
		double res = 0;
		// ->
		if (le < ri) {
			res = rprefix[ri] - rprefix[le];
		}
		// <-
		else if (le > ri) {
			res = lprefix[ri] - lprefix[le];
		}
		cout << res << "\n";
		
	}
	return 0;
}
