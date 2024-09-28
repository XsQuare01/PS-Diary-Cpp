#define MAX 300000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int res1, res2;
    res1 = N * 0.78;
    res2 = N - (N * 0.2 * 0.22);
    cout << res1 << " " << res2;


    return 0;
}