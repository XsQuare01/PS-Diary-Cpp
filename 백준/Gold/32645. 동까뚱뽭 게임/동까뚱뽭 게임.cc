#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int N, A = 0, B = 0;
int parent[MAX+1];
int res[MAX+1];
vector<int> edge[MAX+1];

// 0: 동우의 승리, 1: 혁준의 승리
int DFS(int node){
	int r = 1;
	for(auto a: edge[node]){
		if(parent[node] == a){
			continue;
		}

		parent[a] = node;
		if(DFS(a)){
			r = 0;
		}
	}

	res[node] = r;
	return res[node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for(int i = 1; i < N; i++){
		int st,ed;
		cin >> st >> ed;
		edge[st].push_back(ed);
		edge[ed].push_back(st);
	}
	
	DFS(1);
	for(int i = 1; i <= N; i++){
		if(res[i]){
			cout << "uppercut\n";
		}
		else{
			cout << "donggggas\n";
		}
	}
	return 0;
}