#include <bits/stdc++.h>
#define MAX 100000
#define INF 2100000000
#define MOD 998244353

using namespace std;

int N, A, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> A >> B;
    if(A == B){
        cout << "Anything";
    }
    else if(A < B){
        cout << "Bus";
    }
    else{
        cout << "Subway";
    }

    return 0;
}
