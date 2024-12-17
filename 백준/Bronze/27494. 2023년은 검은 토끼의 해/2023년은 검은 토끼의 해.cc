#include <bits/stdc++.h>
#define MAX 100000
#define INF 2100000000
#define MOD 998244353

using namespace std;

int N;
int cnt = 0;
int check[] = {3, 2, 0, 2};
int parr[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

bool check2023(int num){
    int idx = 0;
    int len = ceil(log10(num));
    for(int i = 1; i <= len; i++){
        if(idx >= 4){
            break;
        }
        int t = num % parr[i] / parr[i-1];
        if(t == check[idx]){
            idx++;
        }
    }

    return idx >= 4;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 2023; i <= N; i++){
        if(check2023(i)){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
