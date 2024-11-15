#define MAX 1000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M, Q;
int arr[MAX+1][MAX+1];
long long prefix[MAX+1][MAX+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }
    prefix[1][1] = arr[1][1];
    for(int i = 1; i <= N; i++){
        prefix[i][1] = prefix[i-1][1] + arr[i][1];
    }
    for(int i = 1; i <= M; i++){
        prefix[1][i] = prefix[1][i-1] + arr[1][i];
    }

    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= M; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j];
        }
    }

    for(int i = 0; i < Q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
        long long area = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];

        long long res = area / cnt;
        cout << res << "\n";
    }

    return 0;
}