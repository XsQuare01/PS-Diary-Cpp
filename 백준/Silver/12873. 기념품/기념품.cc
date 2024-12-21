#include <bits/stdc++.h>
#define MAX 5000
#define INF 2100000000
#define MOD 1000000007

using namespace std;

long long N;
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        q.push(i);
    }

    for(int i = 1; i < N; i++){
        long long t = (1LL * i * i * i) % (N-i+1);
        if(t == 0){
            t = N-i+1;
        }
        for(int j = 1; j < t; j++){
            int f = q.front();
            q.pop();
            q.push(f);
        }
        // //Debug
        // cout << q.front() << " ";
        q.pop();
    }

    cout << q.front();
    return 0;
}
