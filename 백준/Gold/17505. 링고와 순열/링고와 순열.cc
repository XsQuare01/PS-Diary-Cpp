#define MAX 100000
#define MOD 1000000000

#include<bits/stdc++.h>

using namespace std;

long long N, K;
vector<long long> res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    long long last = N;
    while(K >= (last-1) && last > 0){
        res.push_back(last);
        K -= (last-1);
        last--;
    }
    long long joker = 0;
    if(K != 0){
        joker = K+1;
        res.push_back(joker);
    }
    for(long long i = 1; i <= N; i++){
        if(i == joker || i > last){
            continue;
        }
        res.push_back(i);
    }
    
    for(long long i = 0; i < N; i++){
        cout << res[i] << " ";
    }
    return 0;
}