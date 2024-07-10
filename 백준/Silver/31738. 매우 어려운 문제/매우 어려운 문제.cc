#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

long long N, M;
long long res = 1;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    if(N >= M){
        cout << 0;
    }
    if(N < M){
        for(int i = 2; i <= N; i++){
            res *= i;
            res %= M;
        }
        cout << res;
    }
    return 0;
}