#define MAX 100000
#define MOD 1000000007
#define INF 20

#include<bits/stdc++.h>

using namespace std;

int N, M, K;
int res = 0;
int len = 0;
int arr[MAX + 1];
vector<pair<int, int>> vec;

pair<int, int> checkWinner(pair<int, int> team, int idx){
    if(arr[team.first] < arr[idx]){
        team.second = team.first;
        team.first = idx;
    }
    else if(arr[team.second] < arr[idx]){
        team.second = idx;
    }

    return team;
}

void DFS(int cnt, pair<int, int> team){
    if(cnt == len){
        if(team.first == K && (arr[team.first] > arr[team.second] || team.first == team.second)){
            res++;
        }
        return ;
    }

    auto [t1, t2] = vec[cnt];
    arr[t1]++;
    DFS(cnt+1, checkWinner(team, t1));
    arr[t1]--;

    arr[t2]++;
    DFS(cnt+1, checkWinner(team, t2));
    arr[t2]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int t1, t2, s;
        cin >> t1 >> t2 >> s;
        if(s == 0){
            vec.push_back({t1, t2});
        }
        else if(s == 1){
            arr[t1]++;
        }
        else if(s == 2){
            arr[t2]++;
        }
    }
    len = vec.size();

    DFS(0, {K, 0});
    cout << res;

    return 0;
}