#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#define INF 987654321
#define MOD 998244353

#include<bits/stdc++.h>

using namespace std;

int T, N, M;
vector<pair<int, int>> edge[MAX+1];
int parent[MAX+1];
int dp[MAX+1];

void init(){
	for(int i = 1; i <= N; i++){
		edge[i] = vector<pair<int,int>>();
		dp[i] = INF;
		parent[i] = 0;
	}
}

int DFS(int node, int weight){
	int res = 0;

	// 리프 노드
	if(edge[node].size() == 1 && node != 1){
		res = INF;
	}

	for(auto a: edge[node]){
		if(a.first == parent[node]){
			continue;
		}
		parent[a.first] = node;
		res += DFS(a.first,a.second);
	}

	return min(res, weight);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for(int i = 0; i < T; i++){

		cin >> N >> M;
		init();
		for(int i = 0; i < M; i++){
			int s,e,w;
			cin >> s >> e >> w;
			edge[s].push_back({e, w});
			edge[e].push_back({s, w});
		}

		cout << DFS(1,INF) << "\n";
	}
	

	return 0;
}