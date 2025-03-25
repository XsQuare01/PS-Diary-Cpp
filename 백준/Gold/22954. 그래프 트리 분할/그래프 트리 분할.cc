#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#define EMAX 200000
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

struct edge{
	int st = -1;
	int ed = -1;
	int idx = -1;
};

int N,M;
edge earr[EMAX+1];
int edge_cnt[MAX+1];
vector<edge*> edge_vec[MAX+1];

int parent[MAX+1] = {0,};
int flag[MAX+1] = {0,};
vector<pair<int,int>> tree_root;

int DFS(int node,int color,int mode){

	// 그래프 탐색 DFS
	if(mode == 0){
		flag[node] = color;
	}
	// 노드 출력 DFS
	else if(mode == 1){
		cout << node << " ";
	}
	int cnt = 1;

	for(auto a: edge_vec[node]){
		int st = a->st;
		int ed = a->ed;

		// 끊어진 edge
		if(st == -1 || ed == -1){
			continue;
		}

		// 부모 node 제외
		if(st == parent[node] || ed == parent[node]){
			continue;
		}

		// 그래프 탐색 DFS에서 cycle 감지
		if((st != node && flag[st] && !mode) || (ed != node && flag[ed] && !mode)){
			edge_cnt[st]--;
			edge_cnt[ed]--;

			a->st = -1;
			a->ed = -1;

			continue;
		}

		if(mode == 2){
			cout << a->idx << " ";
		}

		// 부모 설정
		if(st == node){
			parent[ed] = node;
			cnt += DFS(ed,color,mode);
		} else if(ed == node){
			parent[st] = node;
			cnt += DFS(st,color,mode);
		}
	}
	return cnt;
}

void cuttingLeaf(){
	for(int i = 2; i <= N; i++){
		if(edge_cnt[i] == 1){
			for(auto a: edge_vec[i]){
				int st = a->st;
				int ed = a->ed;

				// 끊어진 edge
				if(st == -1 || ed == -1){
					continue;
				}

				edge* e = a;

				// edge 끊기
				e->st = -1;
				e->ed = -1;

				tree_root[0].second -= 1;
				tree_root.push_back({i,1});
				return ;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for(int i = 1; i <= M; i++){
		int s,e;
		cin >> s >> e;
		earr[i].st = s;
		earr[i].ed = e;
		earr[i].idx = i;

		edge_cnt[s]++;
		edge_cnt[e]++;
		edge_vec[s].push_back(&earr[i]);
		edge_vec[e].push_back(&earr[i]);
	}

	int color = 1;
	for(int i = 1; i <= N; i++){
		if(!flag[i]){
			int c = DFS(i,color++,0);
			tree_root.push_back({i,c});
		}
	}

	if(color > 3){
		cout << "-1";
		return 0;
	}
	// 트리 하나를 끊어 2개로 만들어야 함
	else if(color == 2){
		// 둘로 쪼개기 불가능
		if(N <= 2){
			cout << "-1";
			return 0;
		}

		cuttingLeaf();
	}

	// 그래프를 tree 2개로 쪼갬
	int left_tree = tree_root[0].second;
	int right_tree = tree_root[1].second;

	if(left_tree == right_tree){
		cout << "-1";
		return 0;
	}

	int left_root = tree_root[0].first;
	int right_root = tree_root[1].first;

	cout << left_tree << " " << right_tree << "\n";
	DFS(left_root,0,1);
	cout << "\n";
	DFS(left_root,0,2);
	cout << "\n";
	DFS(right_root,0,1);
	cout << "\n";
	DFS(right_root,0,2);

	return 0;
}