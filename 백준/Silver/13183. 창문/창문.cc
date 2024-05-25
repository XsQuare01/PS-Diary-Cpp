#define MOD 1000000007

#include<bits/stdc++.h>

using namespace std;

long long H, W, R;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    H %= MOD;
    W %= MOD;
    R = (H+2)*(W+2)%MOD;
    cout << R;
    return 0;
}