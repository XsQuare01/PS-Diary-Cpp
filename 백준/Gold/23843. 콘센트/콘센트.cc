#include <bits/stdc++.h>
#define MAX 10000
#define INF 10
#define MOD 987654321

using namespace std;

int N, M;
int arr[MAX];
int rarr[INF] = {0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N, greater<int>());
    for(int i = 0; i < N; i++){
        int minimum = MOD;
        int idx = -1;
        for(int j = 0; j < M; j++){
            if(rarr[j] < minimum){
                idx = j;
                minimum = rarr[j];
            }
        }

        rarr[idx] += arr[i];
    }

    int minimum = -1;
    for(int i = 0; i < M; i++){
        minimum = max(minimum, rarr[i]);
    }

    cout << minimum;
    return 0;
}
