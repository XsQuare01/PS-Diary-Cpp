#define NMAX 1000
#define TMAX 300000
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

struct cmp{
	bool operator()(pair<int, int> a, pair<int, int> b){
		if(a.first != b.first){
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

int A, B, N;
vector<pair<int, int>> vec;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
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

		// 상민의 인형만들기
		if(c == 'B'){
			int st = max(t, aidx);
			for(int j = 0; j < m; j++){
				pq.push({st, 1});
				st += A;
			}
			aidx = st;
		}
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
			pq.push({st, 2});
			st += B;
		}

		bidx = st;
	}

	while(!pq.empty()){
		auto a = pq.top();
		pq.pop();

		if(a.second == 1){
			avec.push_back(cnt++);
		}
		else if(a.second == 2){
			bvec.push_back(cnt++);
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