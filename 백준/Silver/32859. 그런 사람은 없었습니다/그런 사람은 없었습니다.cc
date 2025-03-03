#define MAX 2001
#define TMAX 300000
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

int N, M, S;
int R = 0;

int arr1[MAX];
int arr2[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> S;
	int cnt = 1;

	for(int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;

		
		// u번 회원이 입금
		if(v){
			arr1[u] = cnt;		// 입금 시간: i
		}
		// u번 회원이 폼 제출
		else{
			arr2[u] = cnt++;	// 폼 제출 시간: i
		}
	}
	for(int i = 1; i < MAX; i++){
		if(!arr1[i]){
			arr1[i] = INF;
		}

		if(!arr2[i]){
			arr2[i] = cnt;
		}
	}

	//Debug
	// for(int i = 1; i <= N; i++){
	// 	cout << arr1[i] << " " << arr2[i] << "\n";
	// }

	vector<int> vec;
	for(int i = 1; i <= N; i++){
		if(arr1[i] + S <= arr2[i]){
			vec.push_back(i);
		}
	}

	if(vec.empty()){
		cout << -1;
	}
	else{
		for(auto a: vec){
			cout << a << "\n";
		}
	}


	
	return 0;
}