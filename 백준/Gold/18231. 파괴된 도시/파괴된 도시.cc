#include <bits/stdc++.h>
#define MAX 2000
#define INF 2100000000

using namespace std;

int N, M, K;
vector<int> edge[MAX+1];
bool carr[MAX+1] = {false, };
bool rarr[MAX+1] = {false, };
vector<int> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    cin >> K;
    for(int i = 0; i < K; i++){
        int c;
        cin >> c;
        carr[c] = true;
        rarr[c] = true;
    }

    for(int i = 1; i <= N; i++){
        bool flag = true;
        for(auto a: edge[i]){
            if(!carr[a]){
                flag = false;
                break;
            }
        }

        // 폭탄 지우기
        if(flag && carr[i]){
            res.push_back(i);
            rarr[i] = false;
            for(auto a: edge[i]){
                rarr[a] = false;
            }
        }
    }

    // 폭탄 지우기 검사
    for(int i = 1; i <= N; i++){
        if(rarr[i]){
            res = vector<int>();
            break;
        }
    }

    if(res.empty()){
        cout << -1;
        return 0;
    }

    cout << res.size() << "\n";
    for(auto a: res){
        cout << a << " ";
    }

    return 0;
}
