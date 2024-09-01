#define MAX 1000
#define MOD 1000000000
#define INF 10000

#include<bits/stdc++.h>

using namespace std;

int N, K;
pair<int, int> arr[MAX];
int dp[INF+1] = {0, };
int res = -1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    for(int i = 0; i < K; i++){
        int im = arr[i].first;
        int ti = arr[i].second;

        for(int j = N; j > 0; j--){
            if(!dp[j]){
                continue;
            }

            if(j + ti > N){
                continue;
            }

            dp[j + ti] = max(dp[j] + im, dp[j + ti]);
        }
        dp[ti] = max(dp[ti], im);
    }

    for(int i = N; i > 0; i--){
        res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}