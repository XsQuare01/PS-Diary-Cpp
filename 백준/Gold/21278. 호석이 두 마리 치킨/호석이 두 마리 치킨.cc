#include <bits/stdc++.h>
#define MAX 100
#define INF 2100000000

using namespace std;

int N, M;
vector<int> edge[MAX+1];
int dist[MAX+1][MAX+1] = {0, };

queue<pair<int, int>> q;

int res = INF;
int c1 = 1, c2 = 2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }

    for(int i = 1; i <= N; i++){
        q = queue<pair<int, int>>();

        for(auto a: edge[i]){
            q.push({a, 1});
        }

        // BFS -> 각 노드간 거리
        while(!q.empty()){
            int node = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(dist[i][node]){
                continue;
            }

            dist[i][node] = cnt;

            for(auto b: edge[node]){
                if(dist[i][b]){
                    continue;
                }

                q.push({b, cnt+1});
            }
        }
        
        dist[i][i] = 0;
    }

    //Debug
    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1; i <= N; i++){
        for(int j = i+1; j <= N; j++){
            int tres = 0;
            for(int k = 1; k <= N; k++){
                tres += min(dist[i][k], dist[j][k]);
            }
            
            if(res > tres){
                c1 = i;
                c2 = j;
                res = tres;
            }
        }
    }

    cout << c1 << " " << c2 << " " << res * 2;
    return 0;
}
