#define MAX 100
#define MOD 1000000007
#define INF 26

#include<bits/stdc++.h>

using namespace std;

int N, M;
long long sum, res;

inline long long totalSum(long long n){
    return n * (n+1) * (2*n + 1) / 6;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        sum += t + 1;
    }


    int rest = M - sum;
    if(rest <= 0){
        cout << 0;
        return 0;
    }
    long long share = rest / (N + 1);
    long long remainer = rest % (N + 1);
    res = remainer * totalSum(share + 1) + (N + 1 - remainer) * totalSum(share);

    cout << res;
    return 0;
}