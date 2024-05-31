
#include<bits/stdc++.h>

using namespace std;

long long N, M;
long long res = 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        res *= i;
    }
    cout << res;
    return 0;
}
 