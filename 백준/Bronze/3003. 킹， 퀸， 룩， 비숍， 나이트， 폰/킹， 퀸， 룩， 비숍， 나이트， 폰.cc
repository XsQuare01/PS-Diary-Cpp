#define MAX 1000000
#define MOD 1000000000
#define INF 10000

#include<bits/stdc++.h>

using namespace std;

int K, Q, R, B, N, P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> Q >> R >> B >> N >> P;
    cout << 1 - K << " " << 1 - Q << " " << 2 - R << " " << 2 - B << " " << 2 - N << " " << 8 - P;

    return 0;
}