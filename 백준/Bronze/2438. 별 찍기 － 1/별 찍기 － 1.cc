#define MAX 100
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}