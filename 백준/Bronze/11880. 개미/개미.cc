#define MAX 100000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int T;
long long res = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        long long tres1 = (a + b) * (a + b) + c * c;
        long long tres2 = (a + c) * (a + c) + b * b;
        long long tres3 = (b + c) * (b + c) + a * a;
        res = min(tres1, min(tres2, tres3));
        cout << res <<"\n";
    }

    return 0;
}