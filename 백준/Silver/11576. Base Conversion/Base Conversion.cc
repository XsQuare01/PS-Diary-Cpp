#define MAX 100
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

int A, B;
int N;
int arr[MAX];
long long res = 0;
vector<int> brr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	reverse(arr, arr + N);
	for(int i = 0; i < N; i++){
		res += arr[i] * pow(A, i);
	}

	while(res > 0){
		int t = res % B;
		brr.push_back(t);
		res /= B;
	}

	reverse(brr.begin(), brr.end());
	for(auto a: brr){
		cout << a << " ";
	}

	return 0;
}