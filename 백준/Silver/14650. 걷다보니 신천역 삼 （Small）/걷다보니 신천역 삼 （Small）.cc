#define MAX 9

#include<bits/stdc++.h>

using namespace std;

int N;
int dp[MAX+1][2*MAX+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i = 2; i <= MAX; i++){
        for(int j = 0; j <= 2*MAX; j++){
            for(int k = 0; k < 3; k++){
                if(j+k > 2*MAX){
                    break;
                }
                dp[i][j+k] += dp[i-1][j];
            }
        }
    }
    cin >> N;
    int cnt = 0;
    for(int i = 1; i <= 2*MAX; i++){
        if(!(i%3)){
            cnt += dp[N][i];
        }
    }
    cout << cnt;

    return 0;
}