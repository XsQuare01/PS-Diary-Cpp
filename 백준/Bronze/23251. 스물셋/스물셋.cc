#define MAX 1000000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int T, N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        cout << N * 23 << "\n";
    }

    return 0;
}