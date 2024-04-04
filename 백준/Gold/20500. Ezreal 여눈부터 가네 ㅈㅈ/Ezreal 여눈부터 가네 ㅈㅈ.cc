#define MAX 1515
#define MOD 1000000007
#define EZ 15
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int T1 = 10%EZ;
int T2 = 50%EZ;
long long dp[EZ];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = 1;
    dp[5] = 1;

    cin >> N;
    for(int i = 1; i < N; i++){
        long long tdp[EZ] = {0, };
        for(int j = 0; j < EZ; j++){
            if(!dp[j]){
                continue;
            }
            int idx1 = (j + T1) % EZ;
            tdp[idx1] += dp[j];
            tdp[idx1] %= MOD;

            int idx2 = (j + T2) % EZ;
            tdp[idx2] += dp[j];
            tdp[idx2] %= MOD;
        }

        for(int j = 0; j < EZ; j++){
            dp[j] = tdp[j];
            dp[j] %= MOD;
        }
        T1 *= 10;
        T1 %= EZ;
        T2 *= 10;
        T2 %= EZ;
    }
    cout << dp[0];

    return 0;
}