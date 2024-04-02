#define MAX 500000
#define INF 987654321

#include<bits/stdc++.h>

//A

using namespace std;

int N;
int arr[MAX+1];
int dp[3][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        int t;
        cin >> t;
        arr[i] = t % 3;
    }

    long long res = 0;
    int s1 = 0;
    int s2 = 0;
    dp[0][0] = 1; // i = 1;
    for(int i = 1; i <= N; i++){
        s1 = (s1 + arr[i]) % 3;
        s2 = (s2 + arr[i] * arr[i]) % 3;
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                int t = ((s1 - x) * (s1 - x) - (s2 - y)) % 3;
                if(t){
                    continue;
                }
                res += dp[x][y];
            }
        }
        dp[s1][s2]++;
    }
    cout << res;
    return 0;
}