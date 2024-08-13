#define MAX 5000000
#define MOD 13

#include<bits/stdc++.h>

using namespace std;

int N, L, C;
int res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> C;
    int len = 0;
    int cnt = 0;
    while(len + L <= C && cnt + 1 <= N){
        len += (L+1);
        cnt++;
    }

    if(cnt % MOD == 0){
        cnt -= 1;
    }
    res = N / cnt;
    N -= (res * cnt);

    int t = ((cnt - 1) % MOD == 0) ? 2 : (cnt - 1) % MOD;

    //Debug
    // cout << N << " " << cnt << " " << t << "\n";
    if(N == 0){
        // continue
    }
    else if(N % MOD){
        res++;
    }
    else if(N + t <= cnt){
        res++;
    }
    else{
        res += 2;
    }
    cout << res;
    return 0;
}