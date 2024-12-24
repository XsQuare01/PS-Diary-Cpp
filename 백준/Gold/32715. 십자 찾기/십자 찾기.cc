#include <bits/stdc++.h>
#define MAX 2500
#define INF 2100000000
#define MOD 1000000007

using namespace std;

int N, M, K;
int arr[MAX][MAX];
int lprefix[MAX][MAX];
int rprefix[MAX][MAX];
int uprefix[MAX][MAX];
int dprefix[MAX][MAX];
int res = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    K += 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < M; j++){
            if(arr[i][j] == 0){
                cnt = 0;
            }
            else{
                cnt++;
            }
            lprefix[i][j] = cnt;
        }
    }

    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = M-1; j >= 0; j--){
            if(arr[i][j] == 0){
                cnt = 0;
            }
            else{
                cnt++;
            }
            rprefix[i][j] = cnt;
        }
    }

    for(int i = 0; i < M; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(arr[j][i] == 0){
                cnt = 0;
            }
            else{
                cnt++;
            }
            uprefix[j][i] = cnt;
        }
    }

    for(int i = 0; i < M; i++){
        int cnt = 0;
        for(int j = N-1; j >= 0; j--){
            if(arr[j][i] == 0){
                cnt = 0;
            }
            else{
                cnt++;
            }
            dprefix[j][i] = cnt;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(lprefix[i][j] >= K && rprefix[i][j] >= K && uprefix[i][j] >= K && dprefix[i][j] >=K){
                res++;
            }
        }
    }

    cout << res;
    return 0;
}
