#define MAX 1000
#define NUM 10
#define MOD 1234567

#include<bits/stdc++.h>

using namespace std;

int T, N;
vector<int> varr[NUM];
long long dp[MAX + 1][NUM];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    varr[0].push_back(7);

    varr[1].push_back(2);
    varr[1].push_back(4);

    varr[2].push_back(1);
    varr[2].push_back(5);
    varr[2].push_back(3);

    varr[3].push_back(2);
    varr[3].push_back(6);
    
    varr[4].push_back(1);
    varr[4].push_back(5);
    varr[4].push_back(7);

    varr[5].push_back(2);
    varr[5].push_back(4);
    varr[5].push_back(6);
    varr[5].push_back(8);

    varr[6].push_back(3);
    varr[6].push_back(5);
    varr[6].push_back(9);

    varr[7].push_back(4);
    varr[7].push_back(8);
    varr[7].push_back(0);

    varr[8].push_back(5);
    varr[8].push_back(7);
    varr[8].push_back(9);

    varr[9].push_back(6);
    varr[9].push_back(8);

    cin >> T;
    for(int i = 0; i < NUM; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= MAX; i++){
        long long tdp[NUM] = {0, };
        for(int j = 0; j < NUM; j++){
            for(auto a: varr[j]){
                tdp[a] += dp[i-1][j];
                tdp[a] %= MOD;
            }
        }

        for(int j = 0; j < NUM; j++){
            dp[i][j] = tdp[j];
        }
    }
    for(int i = 0; i < T; i++){
        cin >> N;
        long long res = 0;
        for(int j = 0; j < NUM; j++){
            res += dp[N][j];
        }
        cout << res % MOD << "\n";
    }

    return 0;
}