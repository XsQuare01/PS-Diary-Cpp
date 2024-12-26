#include <bits/stdc++.h>
#define MAX 30
#define INF 2100000000
#define MOD 1000000007

using namespace std;

int R, C, W;
long long arr[MAX][MAX];
long long res = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> W;
    R -= 1;
    C -= 1;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j <= i; j++){
            arr[i][j] = 1;
        }
    }
    for(int i = 2; i < MAX; i++){
        for(int j = 1; j < i; j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    // for(int i = 0; i < MAX; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    for(int i = R; i < R+W; i++){
        for(int j = C; j <= i - R + C; j++){
            res += arr[i][j];

            //Debug
            // cout << arr[i][j] << " ";
        }
    }

    cout << res;
    return 0;
}
