#define MAX 800
#define INF 60000000

#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int n, m, u, v;
int res[4][4];
vector<pair<int, int>> vec[MAX + 1];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        vec[s].push_back({e, w});
        vec[e].push_back({s, w});
    }
    cin >> u >> v;

    int darr[4] = {1, u, v, n};

    for(int i = 0; i < 3; i++){
        int a = darr[i];
        pq = priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>();
        int dist[MAX + 1];
        for(int i = 1; i<= n; i++){
            dist[i] = INF;
        }
        dist[a] = 0;
        pq.push({a, 0});

        while(!pq.empty()){
            int s = pq.top().first;
            int d = pq.top().second;
            pq.pop();

            if(dist[s] < d){
                continue;
            }

            for(auto [e, w]: vec[s]){
                if(dist[e] <= d + w){
                    continue;
                }

                dist[e] = d + w;
                pq.push({e, dist[e]});
            }
        }

        for(int j = 0; j < 4; j++){
            int b = darr[j];

            res[i][j] = dist[b];
        }

    }

    int len = min(res[0][1] + res[1][2] + res[2][3], res[0][2] + res[2][1] + res[1][3]);
    if(len >= INF){
        len = -1;
    }
    cout << len;

    
    return 0;
}