#define MAX 1000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, K, TK, len, res;
int arr[MAX+1];
int parr[MAX+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        if(!(arr[i] % 2)){
            parr[len] = parr[len++];
        }
        if(arr[i] % 2){
            parr[len]++;
        }
    }
    res = upper_bound(parr, parr + len, TK) - parr;
    TK = K + parr[0];
    for(int i = 1; i < len; i++){
        int idx = upper_bound(parr, parr + len, TK) - parr;
        res = max(res, idx - i + 1);
        TK = K + parr[i];
    }
    cout << res;
    return 0;
}