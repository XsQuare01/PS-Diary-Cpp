#define MAX 100
#define TMAX 300000
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	cout << min(N, M);

	
	return 0;
}