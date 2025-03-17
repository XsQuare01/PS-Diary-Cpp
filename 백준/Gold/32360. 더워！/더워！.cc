#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int N, M, K, C, B;
int SY, SX, DY, DX;
int arr[MAX][MAX];
int darr[][2] = {
	{-1,0},
	{0,-1},
	{1,0},
	{0,1},
	{0,0}
};

inline bool inBoundary(int y,int x){
	return y >= 0 && x >= 0 && y < N && x < M;
}

queue<pair<pair<int,int>,pair<int,int>>> q;	// {{y, x}, {p, t}}: (y, x)에서 피로도가 p이고 시간이 t
int flag[MAX][MAX][MAX];	//[i][j][k]: (i, j) 에서 피로도가 k일때의 최소 거리

int BFS(){
	q.push({{SY,SX},{0,1}});
	flag[SY][SX][0] = 0;

	while(!q.empty()){
		auto a = q.front();
		q.pop();

		int y = a.first.first;
		int x = a.first.second;
		int p = a.second.first;
		int t = a.second.second;

		// 도착
		if(y == DY && x == DX){
			int q = 0;
			continue;
		}

		for(auto [dy,dx]: darr){
			int ty = y + dy;
			int tx = x + dx;

			// 범위 밖
			if(!inBoundary(ty,tx)){
				continue;
			}

			// 벽
			if(arr[ty][tx] == 1){
				continue;
			}
			
			int tp = 0;
			// 실내
			if(arr[ty][tx] == -1){
				tp = max(0, p - K);
			}
			// 실외
			else if(arr[ty][tx] == 0){
				tp = min(MAX, p + C);
			}

			// 탈진
			if(tp >= MAX){
				continue;
			}

			if(flag[ty][tx][tp] <= t){
				continue;
			}
			flag[ty][tx][tp] = t;

			q.push({{ty, tx},{tp, t+1}});
		}
	}

	int ret = INF;
	for(int i = 0; i < MAX; i++){
		ret = min(ret,flag[DY][DX][i]);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K >> C;

	// 초기화
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < MAX; k++){
				flag[i][j][k] = INF;
			}
		}
	}

	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		for(int j = 0; j < M; j++){
			char c = s[j];
			switch(c)
			{
				// 시작 지점
				case 'S':
					SY = i;
					SX = j;
					arr[i][j] = -1;	// 실내
					break;
				
				//길
				case '.':
					arr[i][j] = 0;		// 야외
					break;

				// 벽 - 못지나감
				case '#':
					arr[i][j] = 1;
					break;

				// 건물 내부
				case 'H':
					arr[i][j] = -1;	// 실내
					break;

				case 'E':
					DY = i;
					DX = j;
					arr[i][j] = 0;		// 야외
					break;
			}
		}
	}

	int ret = BFS();
	if(ret == INF){
		ret = -1;
	}
	cout << ret;
	return 0;
}