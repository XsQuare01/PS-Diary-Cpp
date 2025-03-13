#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000000
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX];

long long parametricSearch(int value){
	long long res = 0;
	for(int i = 0; i < N; i++){
		if(arr[i] <= value){
			continue;
		}
		res += (arr[i] - value);
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	long long st = 0;
	long long ed = INF;
	while(st <= ed){
		long long mid = (st + ed) / 2;
		long long res = parametricSearch(mid);

		if(res >= M){
			st = mid+1;
		}
		else if(res < M){
			ed = mid-1;
		}
	}

	cout << st-1;
	return 0;
}