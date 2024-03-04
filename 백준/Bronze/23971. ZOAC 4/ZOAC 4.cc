#define MAX 1000
#define HMAX 500000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int h, w, n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> n >> m;
    int res = ceil(1.0 * h / (n + 1)) * ceil(1.0 * w / (m + 1));
    cout << res;

    return 0;
}
