#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[MAX];
pair<int, int> dp[MAX][2]; //[0]: y, [1]: x

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int tx, ty;
        cin >> tx >> ty;
        arr[i] = {tx, ty};
    }
    dp[0][0] = {arr[0].first, arr[0].second};
    dp[0][1] = {arr[0].second, arr[0].first};

    for(int i = 1; i < N; i++){
        int h0 = dp[i-1][0].second;
        int w0 = dp[i-1][0].first;

        int h1 = dp[i-1][1].second;
        int w1 = dp[i-1][1].first;

        bool f0 = w0 + abs(h0 - arr[i].second) > w1 + abs(h1 - arr[i].second);
        if(f0){
            int g0 = w0 + arr[i].first + abs(h0 - arr[i].second);
            dp[i][0] = {g0, arr[i].second};
        }
        if(!f0){
            int g0 = w1 + arr[i].first + abs(h1 - arr[i].second);
            dp[i][0] = {g0, arr[i].second};
        }

        bool f1 = w0 + abs(h0 - arr[i].first) >  w1 + abs(h1 - arr[i].first);
        if(f1){
            int g1 = w0 + arr[i].second + abs(h0 - arr[i].first);
            dp[i][1] = {g1, arr[i].first};
        }
        if(!f1){
            int g1 = w1 + arr[i].second + abs(h1 - arr[i].first);
            dp[i][1] = {g1, arr[i].first};
        }
    }
    cout << max(dp[N-1][0].first, dp[N-1][1].first);
    return 0;
}