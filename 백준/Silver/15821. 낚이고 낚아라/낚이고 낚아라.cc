#include <bits/stdc++.h>
#define MAX 100
#define INF 2100000000
#define MOD 998244353

using namespace std;

int K, N;
vector<long long> dist;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int P;
        cin >> P;
        long long maximum = -1;
        for(int j = 0; j < P; j++){
            long long y, x;
            cin >> y >> x;
            long long tdist = y * y + x * x;

            maximum = max(maximum, tdist);
        }

        dist.push_back(maximum);
    }

    sort(dist.begin(), dist.end());

    //Debug
    cout << dist[K-1] << ".00";
    return 0;
}
