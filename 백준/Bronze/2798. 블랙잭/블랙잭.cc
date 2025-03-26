#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#define INF 300000

#include<bits/stdc++.h>

using namespace std;

int N, M, R = -1;
int arr[MAX];
int dat[INF];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}


	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			for(int k = j+1; k < N; k++){
				int sum = arr[i] + arr[j] + arr[k];
				if(sum <= M && sum > R){
					R = sum;
				}
			}
		}
	}

	cout << R;
	return 0;
}