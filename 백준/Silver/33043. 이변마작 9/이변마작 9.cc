#include <bits/stdc++.h>
#define MAX 100000
#define INF 6711
#define MOD 1000000007

using namespace std;

int N;
int res = 987654321;

string sarr[MAX];
queue<int> q[INF];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> sarr[i];

        int idx = (int)sarr[i][0] * (int)sarr[i][1];
        q[idx].push(i);

        if(q[idx].size() >= 5){
            int front = q[idx].front();
            res = min(res, i - front + 1);
            
            q[idx].pop();
        }
    }

    if(res == 987654321){
        res = -1;
    }

    cout << res;
    return 0;
}
