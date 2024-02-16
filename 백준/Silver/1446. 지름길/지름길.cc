#define MAX 10000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, d;
int dp[MAX + 1];
vector<pair<pair<int, int>, int>> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    for(int i = 0; i <= d; i++){
        dp[i] = i;
    }

    for(int i = 0; i < n; i++){
        int l, r, w;
        cin >> l >> r >> w;
        v.push_back({{l, r}, w});
    }
    sort(v.begin(), v.end());
    for(auto a: v){
        int l = a.first.first;
        int r = a.first.second;
        int w = a.second;

        if(r > d){
            continue;
        }

        if(dp[r] <= dp[l] + w){
            continue;
        }

        dp[r] = dp[l] + w;
        for(int i = r + 1; i <= d; i++){
            dp[i] = min(dp[i], dp[i-1] + 1);
        }
    }
    cout << dp[d];
    return 0;

}