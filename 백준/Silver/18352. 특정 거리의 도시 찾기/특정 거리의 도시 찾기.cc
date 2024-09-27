#define MAX 300000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M, K, X;
vector<int> varr[MAX+1];
int farr[MAX+1];

void init(){
    for(int i = 1; i <= N; i++){
        farr[i] = INF;
    }
}

void BFS(int idx){
    queue<pair<int, int>> q;
    q.push({idx, 0});
    farr[idx] = 0;

    while(!q.empty()){
        auto a = q.front();
        q.pop();

        int i = a.first;
        int c = a.second;

        if(farr[i] < c){
            continue;
        }

        for(auto b: varr[i]){
            if(farr[b] <= c+1){
                continue;
            }

            farr[b] = c+1;
            q.push({b, c+1});
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> X;
    init();
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        varr[s].push_back(e);
    }

    BFS(X);
    bool f = true;
    for(int i = 1; i <= N; i++){
        if(farr[i] == K){
            f = false;
            cout << i << "\n";
        }
    }
    if(f){
        cout << -1;
    }


    return 0;
}