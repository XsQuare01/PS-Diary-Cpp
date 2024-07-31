#define MAX 100
#define INF 2147483647
#define PI 3.141592653589793

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int t;
            cin >> t;
            arr[i][j] += t;

            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }   

    return 0;
}