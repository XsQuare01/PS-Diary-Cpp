#define MAX 200000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, m;
queue<pair<int, int>> q;
int check[MAX + 1];
int res = INF;
int cnt = 0;

void BFS(int x, int r){
    q.push({x, r});

    while(!q.empty()){
        int idx = q.front().first;
        int ret = q.front().second;
        q.pop();

        if(ret > res){
            return ;
        }

        if(idx > MAX || idx < 0){
            continue;
        }

        if(check[idx] < ret){
            continue;
        }
        

        if(idx == m){
            if(res == INF){
                res = ret;
            }
            cnt++;
        }

        if(idx != m && res > ret){
            check[idx] = ret;
            if(idx != 0){
                q.push({idx * 2, ret + 1});
            }
            q.push({idx - 1, ret + 1});
            q.push({idx + 1, ret + 1});
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i <= MAX; i++){
        check[i] = INF;
    }

    cin >> n >> m;
    if(m <= n){
        res = n - m;
        cnt = 1;
    }
    if(m > n){
        BFS(n, 0);
    }
    cout << res << "\n" << cnt;

    return 0;

}