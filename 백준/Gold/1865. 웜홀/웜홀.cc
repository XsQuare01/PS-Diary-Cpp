#define MAX 500
#define EMAX 2500
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M, W;
vector<pair<pair<int, int>, int>> parr;
vector<pair<pair<int, int>, int>> narr;
int arr[MAX + 1][MAX + 1];
bool farr[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> M >> W;
        //Init
        for(int j = 1; j <= N; j++){
            farr[j] = false;
            for(int k = 1; k <= N; k++){
                if(j == k){
                    arr[j][k] = 0;
                }
                if(j != k){
                    arr[j][k] = INF;
                }
            }
        }
        parr = vector<pair<pair<int, int>, int>>();
        narr = vector<pair<pair<int, int>, int>>();

        //Input
        for(int j = 0; j < M; j++){
            int s, e, w;
            cin >> s >> e >> w;
            parr.push_back({{s, e}, w});
        }
        for(int j = 0; j < W; j++){
            int s, e, w;
            cin >> s >> e >> w;
            narr.push_back({{s, e}, -w});
        }
        bool ret = false;
        for(int j = 1; j<= N; j++){
            bool flag = true;
            if(ret){
                break;
            }
            if(farr[j]){
                continue;
            }
            
            for(int k = 0; k < N; k++){
                flag = true;
                if(k == N-1){
                    flag = false;
                }
                for(auto a: parr){
                    int s = a.first.first;
                    int e = a.first.second;
                    int w = a.second;

                    if(arr[j][s] == INF && arr[j][e] == INF){
                        continue;
                    }

                    if(arr[j][e] > arr[j][s] + w){
                        arr[j][e] = arr[j][s] + w;
                        flag = true;
                    }
                    if(arr[j][s] > arr[j][e] + w){
                        arr[j][s] = arr[j][e] + w;
                        flag = true;
                    }
                }
                for(auto a: narr){
                    int s = a.first.first;
                    int e = a.first.second;
                    int w = a.second;

                    if(arr[j][s] == INF){
                        continue;
                    }

                    if(arr[j][e] > arr[j][s] + w){
                        arr[j][e] = arr[j][s] + w;
                        flag = true;
                        continue;
                    }
                }

                if(k == N-1){
                    for(int l = 1; l <= N; l++){
                        if(arr[j][l] != INF){
                            farr[l] = true;
                        }
                    }

                    if(flag){
                        ret = true;
                        break;
                    }
                }
            
            }
        }

        if(ret){
            cout << "YES" << "\n";
        }
        if(!ret){
            cout << "NO" << "\n";
        }
    }
    return 0;
}
