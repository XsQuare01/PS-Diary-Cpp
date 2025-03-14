#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000000
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int N;
int A = 0,B = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for(int i = 0; i < N; i++){
		int C = A + B;
		A = B;
		B = C;
	}
	cout << A;
	return 0;
}