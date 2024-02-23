#define MAX 10000
#define KMAX 100
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, k, t, m;
int arr[KMAX + 1][KMAX + 1];
int carr[KMAX + 1];
int tarr[KMAX + 1];
pair<pair<int, int>, pair<int, int>> res[KMAX + 1];

int compare(const void* a, const void* b){
    const pair<pair<int, int>, pair<int, int>>* x = (pair<pair<int, int>, pair<int, int>>*)a;
    const pair<pair<int, int>, pair<int, int>>* y = (pair<pair<int, int>, pair<int, int>>*)b;

    if(x->first.first > y->first.first){
        return -1;
    }
    if(x->first.first < y->first.first){
        return 1;
    }
    if(x->first.first == y->first.first){
        if(x->first.second < y->first.second){
            return -1;
        }
        if(x->first.second > y->first.second){
            return 1;
        }
        if(x->first.second == y->first.second){
            if(x->second.first < y->second.first){
                return -1;
            }
            if(x->second.first > y->second.first){
                return 1;
            }
            return 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n >> k >> t >> m;

        //Init
        for(int j = 1; j <= KMAX; j++){
            for(int t = 1; t <= KMAX; t++){
                arr[j][t] = 0;
            }
            carr[j] = 0;
            tarr[j] = 0;
            res[j] = {{0, 0}, {0, 0}};
        }

        for(int j = 0; j < m; j++){
            int id, num, score;
            cin >> id >> num >> score;

            arr[id][num] = max(arr[id][num], score);
            carr[id]++;
            tarr[id] = j;
        }

        for(int j = 1; j <= n; j++){
            res[j] = {{0, 0}, {0, 0}};
            for(int t = 1; t <= k; t++){
                res[j].first.first += arr[j][t];
            }
            res[j].first.second = carr[j];
            res[j].second.first = tarr[j];
            res[j].second.second = j;
        }
        qsort(res + 1, n, sizeof(pair<pair<int, int>, pair<int, int>>), compare);

        for(int j = 1; j <= n; j++){
            int idx = res[j].second.second;
            // Debug
            // cout << idx << " " << res[j].first.first << " " << res[j].first.second << " " << res[j].second.first << "\n";
            if(idx == t){
                cout << j << "\n";
                // cout << i;
                break;
            }
        }
        // cout << "\n";
    }
    
    return 0;

}