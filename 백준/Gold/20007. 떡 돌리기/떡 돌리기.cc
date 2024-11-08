#define MAX 1000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};

int N, M, X, Y;
long long walking = 0, cnt = 1;
int arr[MAX][MAX];
long long farr[MAX];
vector<int> edge[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> X >> Y;
    for(int i = 0; i < M; i++){
        int s, e, w;
        cin >> s >> e >> w;

        edge[s].push_back(e);
        arr[s][e] = w;

        edge[e].push_back(s);
        arr[e][s] = w;
    }

    for(auto a: edge[Y]){
        pq.push({arr[Y][a], a});
    }

    // for(int i = 0; i < N; i++){
    //     farr[i] = INF;
    // }
    // farr[Y] = 0;

    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();

        long long weight = a.first;
        int index = a.second;

        // 이미 방문
        if(farr[index] || index == Y){
            continue;
        }

        // 하루 경과
        if(X - walking < weight * 2){
            if(weight * 2 > X){
                break;
            }
            walking = 0;
            cnt++;
        }
        walking += weight * 2;
        farr[index] = weight;

        for(auto next: edge[index]){
            if(farr[next] || index == Y){
                continue;
            }
            pq.push({weight + arr[index][next], next});
            
        }
    }

    for(int i = 0; i < N; i++){
        if(i == Y){
            continue;
        }
        if(farr[i] == 0){
            cout << -1;
            return 0;
        }
    }

    cout << cnt;
    return 0;
}