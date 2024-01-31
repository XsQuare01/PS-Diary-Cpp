#define MAX 50000
#define INF 60000000

#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int ,int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int n, m;
vector<pair<int ,int>> v[MAX + 1];
priority_queue<pair<int ,int>, vector<pair<int ,int>>, cmp> pq;
int res[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e, w});
        v[e].push_back({s, w});
    }


    for(int i = 1; i <= n; i++){
        res[i] = INF;
    }

    pq.push({1, 0});
    res[1] = 0;
    while(!pq.empty()){
        int s = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if(res[s] < d){
            continue;
        }

        for(auto a: v[s]){
            int e = a.first;
            int w = a.second;

            if(res[e] <= d + w){
                continue;
            }

            res[e] = d + w;
            pq.push({e, res[e]});
        }
        
    }
    cout << res[n];

    return 0;
}