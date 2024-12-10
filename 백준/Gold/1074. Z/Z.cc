#include <bits/stdc++.h>
#define MAX 100000
#define INF 2100000000
#define MOD 998244353

using namespace std;

long long N, R, C;
long long res = 0;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> R >> C;
    for(long long i = N-1; i >= 0; i--){
        long long t = -1;
        long long modular = pow(2, i);

        // 3
        if((R/modular) && (C/modular)){
            //Debug
            t = 3;
            R -= modular;
            C -= modular;
        }
        // 2
        else if((R/modular) && !(C/modular)){
            t = 2;
            R -= modular;
        }
        // 1
        else if(!(R/modular) && (C/modular)){
            t = 1;
            C -= modular;
        }
        // 0
        else{
            t = 0;
        }

        res += t * (long long)pow(2LL, i*2);
        //Debug
        // cout << res << " ";
    }

    cout << res;
    return 0;
}
