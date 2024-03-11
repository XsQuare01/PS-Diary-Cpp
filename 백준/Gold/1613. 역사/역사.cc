#define MAX 400
#define INF 1000000

#include<bits/stdc++.h>

using namespace std;

int n, k, s;
int arr[MAX + 1][MAX + 1];
vector<pair<int, int>> svec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            arr[i][j] = INF;
        }
    }
    for(int i = 0; i < k; i++){
        int st, ed;
        cin >> st >> ed;
        arr[st][ed] = 1;
    }
    
    cin >> s;
    for(int i = 0; i < s; i++){
        int st, ed;
        cin >> st >> ed;
        svec.push_back({st, ed});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int l = 1; l <= n; l++){
                if(j == l){
                    continue;
                }
                if(arr[j][l] < INF){
                    continue;
                }

                arr[j][l] = min(arr[j][l], arr[j][i] + arr[i][l]);
            }
        }
    }

    //Debug
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 0; i < s; i++){
        int st = svec[i].first;
        int ed = svec[i].second;

        if(arr[st][ed] >= INF && arr[ed][st]>= INF){
            cout << 0 << "\n";
            continue;
        }
        if(arr[st][ed] < INF){
            cout << -1 << "\n";
            continue;
        }
        if(arr[ed][st] < INF){
            cout << 1 << "\n";
            continue;
        }
    }

    return 0;   
}
