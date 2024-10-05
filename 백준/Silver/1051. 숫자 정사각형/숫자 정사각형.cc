#define MAX 50
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M;
int res = 0;
int arr[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        for(int j = 0; j < M; j++){
            arr[i][j] = S[j] - '0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 1; i + k < N && j + k < M; k++){
                int n1 = arr[i][j];
                int n2 = arr[i+k][j];
                int n3 = arr[i][j+k];
                int n4 = arr[i+k][j+k];

                if(n1 == n2 && n2 == n3 && n3 == n4){
                    res = max(res, k);
                }
            }
        }
    }

    res++;
    cout << res * res;

    return 0;
}