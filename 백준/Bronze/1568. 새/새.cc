#include <bits/stdc++.h>
#define MAX 2500
#define INF 2100000000
#define MOD 1000000007

using namespace std;

int N;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int sub = 0;
    while(N > 0){
        sub++;
        if(N < sub){
            sub = 1;
        }
        N -= sub;
        cnt++;
    }

    cout << cnt;

    return 0;
}
