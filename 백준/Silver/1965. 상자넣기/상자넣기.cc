#define MAX 1000
#define MOD 1000000009

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX];
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        int u = arr[i];
        for(int j = i+1; j < N; j++){
            int v = arr[j];
            if(u < v){
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < N; i++){
        res = max(res, dp[i]);
    }
    cout << res+1;

    return 0;
}