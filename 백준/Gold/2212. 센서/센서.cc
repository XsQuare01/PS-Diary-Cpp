#define MOD 1000000007
#define NMAX 10000
#define KMAX 1000

#include<bits/stdc++.h>

using namespace std;

int N, K, st, ed, res;
int arr[NMAX];
int darr[NMAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    st = arr[0];
    ed = arr[N-1];
    res = ed - st;

    for(int i = 0; i < N - 1; i++){
        darr[i] = arr[i+1] - arr[i];
    }
    sort(darr, darr + N - 1, greater<int>());
    for(int i = 0; i < K - 1; i++){
        res -= darr[i];
    }
    cout << res;

    return 0;
}