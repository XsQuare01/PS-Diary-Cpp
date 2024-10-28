#define MAX 3000
#define MOD 1000000007
#define INF 26

#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> edge[MAX + 1];
int previous[MAX + 1];
bool dvisited[MAX + 1];
bool bvisited[MAX + 1];
bool cycle[MAX + 1];
bool find_cycle = false;
int dist[MAX + 1];

void BFS(){
    queue<pair<int, int>> q;
    for(int i = 1; i <= N; i++){
        if(cycle[i]){
            dist[i] = 0;
            bvisited[i] = true;
            q.push({i, 0});
        }
    }

    while(!q.empty()){
        int idx = q.front().first;
        int d = q.front().second;
        q.pop();

        dist[idx] = d;

        for(auto a: edge[idx]){
            if(bvisited[a]){
                continue;
            }
            q.push({a, d + 1});
            bvisited[a] = true;
        }
    }
}

void DFS(int st){
    dvisited[st] = true;
    for(auto a: edge[st]){
        if(find_cycle){
            return ;
        }

        // 방문한 노드
        if(dvisited[a] && previous[st] != a){
            cycle[st] = true;
            find_cycle = true;
            int idx = st;
            while(idx != a){
                cycle[previous[idx]] = true;
                idx = previous[idx];
            }

            return ;
        }
        else if(!dvisited[a]){
            previous[a] = st;
            DFS(a);
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int s, e;
        cin >> s >> e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    DFS(1);
    BFS();    

    for(int i = 1; i <= N; i++){
        cout << dist[i] << " ";
    }


    return 0;
}