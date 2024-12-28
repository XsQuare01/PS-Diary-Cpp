#include <bits/stdc++.h>
#define MAX 15
#define INF 2100000000
#define MOD 1000000007

using namespace std;

int N, M, K;
int arr[MAX][MAX];
int res1, res2;

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            arr[i][j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    if(K == 0){
        K = N * M;
    }
    K -= 1;
    int W = K % M;  // 2
    int H = K / M;  // 1

    init();
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    res1 = arr[H][W];

    init();
    for(int i = H+1; i < N; i++){
        for(int j = W+1; j < M; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    //Debug
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    res2 = arr[N-1][M-1];

    cout << res1 * res2;
    

    return 0;
}
