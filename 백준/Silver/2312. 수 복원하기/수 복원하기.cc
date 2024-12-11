#include <bits/stdc++.h>
#define MAX 100000
#define INF 2100000000
#define MOD 998244353

using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;

        for(int j = 2; j * j <= N; j++){
            int cnt = 0;

            while(!(N%j) && N > 1){
                N /= j;
                cnt++;
            }

            if(cnt){
                cout << j << " " << cnt << "\n";
            }
        }

        if(N > 1){
            cout << N << " " << 1 << "\n";
        }
    }

    return 0;
}
