#define _CRT_SECURE_NO_WARNINGS
#define MAX 200000
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

int N;
int arr[MAX];
int sarr[MAX];
int iarr[MAX];
int ancs = 1;
int desc = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", " r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sarr[i] = arr[i];
	}

	sort(sarr, sarr + N);
	for (int i = 0; i < N; i++) {
		iarr[sarr[i]] = i;
	}

	int prev = arr[0];
	for (int i = 1; i < N; i++) {
		int pidx = iarr[prev];
		int idx = iarr[arr[i]];
		if (pidx + 1 != idx) {
			ancs++;
		}
		prev = arr[i];
	}

	cout << min(ancs, 3);
	
	return 0;
}