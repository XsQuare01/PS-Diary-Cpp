#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#define MOD 998244353

#include<bits/stdc++.h>

using namespace std;

long long T, N;

void multiply(long long res[3][3], long long mat[3][3]){
	long long tmp[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			tmp[i][j] = (res[i][0] * mat[0][j]) % MOD
				+ (res[i][1] * mat[1][j]) % MOD
				+ (res[i][2] * mat[2][j]) % MOD;

			tmp[i][j] %= MOD;
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			res[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for(int i = 0; i < T; i++){

		long long matrix[3][3] = {
			{0,1,1},
			{1,0,0},
			{0,1,0}
		};
		
		long long ans[3][3] = {
			{1,0,0},
			{0,1,0},
			{0,0,1}
		};

		cin >> N;
		N -= 3;

		while(N > 0){
			if(N%2 == 1){
				multiply(ans,matrix);
				N -= 1;
			}
			else if(N%2 == 0){
				multiply(matrix,matrix);
				N /= 2;
			}
		}

		long long ret = (ans[0][0] + ans[0][1] + ans[0][2]) % MOD;
		cout << ret << "\n";
	}
	

	return 0;
}