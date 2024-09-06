#define MAX 1000
#define MOD 1000000000
#define INF 10000

#include<bits/stdc++.h>

using namespace std;

long long N, P, R = 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P;
    for(int i = 2; i <= N; i++){
        R *= i;
        R %= P;
    }
    cout << R;

    return 0;
}