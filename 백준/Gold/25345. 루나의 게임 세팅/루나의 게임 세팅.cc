#define MAX 2000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, K;
int arr[MAX];
long long res = 1;
long long division = 1;

long long pow2 = 1;

long long ModularInverse(long long a){
    long long res = 1;
    a %= MOD;

    long long cnt = MOD-2;

    while(cnt > 0){
        if(cnt % 2 == 1){
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        cnt /= 2;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    // #1. nCk
    for(int i = 0; i < K; i++){
        res *= (N - i);
        res %= MOD;
    }

    // #1-1. k!
    for(int i = 1; i <= K; i++){
        division *= i;
        division %= MOD;
    }
    

    res *= ModularInverse(division);
    res %= MOD;


    for(int i = 1; i < K; i++){
        pow2 *= 2;
        pow2 %= MOD;
    }

    res *= pow2;
    res %= MOD;
    
    cout << res;

    return 0;
}