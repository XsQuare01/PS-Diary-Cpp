#include <bits/stdc++.h>
#define MAX 200000
#define INF 2100000000

using namespace std;

int N, K;
int arr[MAX+1];
int prefix[MAX+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    int res = -INF;
    for(int i = K; i <= N; i++){
        int tres = prefix[i] - prefix[i-K];
        res = max(res, tres);
    }

    cout << res;

    return 0;
}
