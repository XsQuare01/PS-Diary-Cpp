#define NMAX 1000
#define TMAX 100000
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

int A, B, N;
vector<pair<int, int>> vec;
vector<int> tarr[TMAX];
int cnt = 1;
int aidx = 0, bidx = 0;

vector<int> avec, bvec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> N;
	for(int i = 0; i < N; i++){
		int t, m;
		char c;
		cin >> t >> c >> m;

		// 상민
		if(c == 'B'){
			int st = max(t, aidx);
			for(int j = 0; j < m; j++){
				tarr[st].push_back(1);
				st += A;
			}
			aidx = st;
		}
		// 지수
		else if (c == 'R'){
			vec.push_back({t, m});
		}
	}

	// 지수의 인형만들기
	for(auto a: vec){
		int t = a.first;
		int m = a.second;

		int st = max(t, bidx);
		for(int j = 0; j < m; j++){
			tarr[st].push_back(2);
			st += B;
		}

		bidx = st;
	}

	for(int i = 0; i < TMAX; i++){
		if(tarr[i].empty()){
			continue;
		}
		for(auto a: tarr[i]){
			if(a == 1){
				avec.push_back(cnt++);
			}
			else if(a == 2){
				bvec.push_back(cnt++);
			}
		}
	}

	cout << avec.size() << "\n";
	for(auto a: avec){
		cout << a << " ";
	}
	cout << "\n" << bvec.size() << "\n";
	for(auto b: bvec){
		cout << b << " ";
	}

	return 0;
}