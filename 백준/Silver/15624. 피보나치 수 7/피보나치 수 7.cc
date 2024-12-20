#include <bits/stdc++.h>
#define MAX 1000000
#define INF 2100000000
#define MOD 1000000007

using namespace std;

int N;
long long arr[MAX+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    arr[0] = 0;
    arr[1] = 1;
    cin >> N;
    for(int i = 2; i <= N; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % MOD;
    }
    cout << arr[N];
    
    return 0;
}
