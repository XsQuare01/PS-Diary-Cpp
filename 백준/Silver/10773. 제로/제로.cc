#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#define INF 300000

#include<bits/stdc++.h>

using namespace std;

int K;
int idx = 0;
int arr[MAX];
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	for(int i = 0; i < K; i++){
		int t;
		cin >> t;
		if(!t){
			idx--;
		}
		else{
			arr[idx++] = t;
		}
	}

	int sum = 0;
	for(int i = 0; i < idx; i++){
		sum += arr[i];
	}
	cout << sum;
	return 0;
}