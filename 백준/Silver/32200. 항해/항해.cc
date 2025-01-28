#define MAX 40000
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

int N, X, Y;
int arr[MAX];
int sum = 0;
int res = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X >> Y;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < N; i++){
		int d1 = arr[i] / X;
		sum += d1;

		int d2 = arr[i] / Y;
		if(arr[i] % Y && (d1 == d2)){
			res += (arr[i] % Y);
		}
	}

	cout << sum << "\n" << res;

	return 0;
}