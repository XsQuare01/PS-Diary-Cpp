#define MAX 100000

#include<bits/stdc++.h>

using namespace std;

int N, M, R;
int cnt = 1;
vector<int> varr[MAX + 1];
int farr[MAX + 1] = {0, };

void DFS(int idx){
    farr[idx] = cnt++;
    for(auto a: varr[idx]){
        if(farr[a]){
            continue;
        }
        DFS(a);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;
    for(int i = 0; i < M; i++){
        int t1, t2;
        cin >> t1 >> t2;
        varr[t1].push_back(t2);
        varr[t2].push_back(t1);
    }
    for(int i = 1; i<= N; i++){
        sort(varr[i].begin(), varr[i].end());
    }

    DFS(R);
    for(int i = 1; i <= N; i++){
        cout << farr[i] << "\n";
    }

    return 0;
}