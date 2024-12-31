#include <bits/stdc++.h>
#define MAX 100000
#define INF 6711
#define MOD 1000000007

using namespace std;

int a, b, c, d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c >> d;
    int res = (a + b + c + d - 1) % 4;
    if(res == 0){
        res = 4;
    }
    cout << res;
    
    return 0;
}
