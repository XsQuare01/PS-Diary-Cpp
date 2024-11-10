#define MAX 1000000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M, R;
vector<int> edge[MAX + 1];
int height[MAX + 1];
int parr[MAX + 1];
bool flag[MAX + 1];

void DFS(int index){
    for(auto a: edge[index]){
        // 이미 방문
        if(flag[a]){
            continue;
        }
        flag[a] = true;
        height[a] = height[index] + 1;
        DFS(a);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> R;
    for(int i = 1; i <= N; i++){
        height[i] = -1;
    }
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;

        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    for(int i = 1; i <= N; i++){
        sort(edge[i].begin(), edge[i].end(), less<int>());
    }

    height[R] = 0;
    flag[R] = true;
    DFS(R);

    for(int i = 1; i <= N; i++){
        cout << height[i] << "\n";
    }


    return 0;
}