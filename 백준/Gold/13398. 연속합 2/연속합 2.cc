#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX];
int dp[MAX+1][2];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	int res = max(dp[0][0], dp[0][1]);
	for(int i = 1; i < N; i++){
		dp[i][0] = max(dp[i-1][0] + arr[i],arr[i]);
		dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0]);
		res = max(res,max(dp[i][0],dp[i][1]));
	}

	cout << res;
	return 0;
}