#define MAX 200000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, m;
bool flag[MAX];
queue<pair<int, int>> q;

bool DFS(int x, int ret){
    if(x >= MAX){
        return false;
    }
    flag[x] = true;
    q.push({x + 1, ret + 1});
    q.push({x - 1, ret + 1});

    if(x == m){
        return true;
    }

    if(x == 0){
        return false;
    }
    return DFS(2*x, ret);
}


int BFS(int x, int cnt){
    q.push({x, cnt});

    while(!q.empty()){
        int idx = q.front().first;
        int ret = q.front().second;
        q.pop();

        if(idx > MAX || idx < 0){
            continue;
        }

        if(flag[idx]){
            continue;
        }

        if(DFS(idx, ret)){  
            return ret;
        }

    }
    return m - n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cout << BFS(n, 0);

    return 0;

}