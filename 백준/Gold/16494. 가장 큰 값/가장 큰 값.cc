#define MAX 20
#define MOD 1000000007
#define INF 10000000

#include<bits/stdc++.h>

using namespace std;


int N, M, res = -INF;
int arr[MAX];
int parr[MAX][MAX];
int dp[MAX][MAX];
vector<int> perm;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        parr[i][i] = arr[i];
        for(int j = i+1; j < N; j++){
            parr[i][j] = parr[i][j-1] + arr[j];
        }
    }

    //Debug
    

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            dp[i][j] = -INF;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            for(int k = i; k <= j; k++){
                for(int l = k; l <= j; l++){
                    dp[i][j] = max(dp[i][j], parr[k][l]);
                }
            }
        }
    }

    for(int i = 0; i < M-1; i++){
        perm.push_back(1);
    }
    for(int i = M-1; i < N-1; i++){
        perm.push_back(0);
    }

    if(N == 1){
        perm.push_back(0);
    }

    res = -INF;
    do{
        int tsum = 0;
        int prev = 0;
        for(int i = 0; i < N; i++){
            if(!perm[i]){
                continue;
            }

            tsum += dp[prev][i];
            prev = i+1;
        }

        if(prev < N){
            tsum += dp[prev][N-1];
        }

        res = max(res, tsum);

    }while(prev_permutation(perm.begin(), perm.end()));


    cout << res;
    return 0;
}