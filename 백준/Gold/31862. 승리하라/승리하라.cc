#define MAX 100000
#define MOD 1000000007
#define INF 20

#include<bits/stdc++.h>

using namespace std;

int N, M, K;
int res = 0;
int maximum = -1;
int arr[MAX + 1];
int sarr[MAX + 1];
vector<pair<int, int>> vec;

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

    // 해당 승 수를 가진 사람이 몇명 있는가?
    for(int i = 1; i <= N; i++){
        int idx = arr[i];

        maximum = max(maximum, idx);
        sarr[idx]++;
    }
    int len = vec.size();
    if(len == 0){
        if(sarr[maximum] == 1 && arr[K] == maximum){
            res = 1;
        }
        cout << res;
        return 0;
    }

    for(int i = 0; i < (1 << len); i++){
        bitset<INF> switch_bitset(i);
        unordered_map<int, int> tmap;
        for(int j = 0; j < len; j++){
            int t1 = vec[j].first;
            int t2 = vec[j].second;

            if(switch_bitset[j]){
                if(tmap.find(t1) != tmap.end()){
                    int cnt = tmap[t1];
                    tmap[t1] = cnt+1;
                }
                else{
                    tmap[t1] = 1;
                }
            }
            else{
                if(tmap.find(t2) != tmap.end()){
                    int cnt = tmap[t2];
                    tmap[t2] = cnt+1;
                }
                else{
                    tmap[t2] = 1;
                }
            }
        }

        int t_max = maximum;
        for(auto [team, score]: tmap){
            int prev_index = arr[team];
            sarr[prev_index]--;

            int cur_index = arr[team] + score;
            sarr[cur_index]++;

            t_max = max(t_max, cur_index);
        }
        

        if(sarr[t_max] == 1){
            int t_k = 0;
            if(tmap.find(K) != tmap.end()){
                t_k = tmap[K];
            }

            if(arr[K] + t_k == t_max){
                res++;
            }
        }

        for(auto [team, score]: tmap){
            int cur_index = arr[team] + score;
            sarr[cur_index]--;

            int prev_index = arr[team];
            sarr[prev_index]++;
        }
    }

    cout << res;

    return 0;
}