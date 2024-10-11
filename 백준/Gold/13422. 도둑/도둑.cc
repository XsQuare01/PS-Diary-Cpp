#define MAX 100000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int T;
long long N, M, K;
long long arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> M >> K;
        for(int j = 0; j < N; j++){
            cin >> arr[j];
        }

        int cnt = 0;
        long long prefix = 0;
        for(int j = 0; j < M; j++){
            prefix += arr[j];
        }

        cnt = prefix < K ? 1 : 0;

        if(N != M){
            int st = 0;
            int ed = M-1;
            for(st = 0; st < N-1; st++){
                ed = (st + M) % N;

                prefix -= arr[st];
                prefix += arr[ed];

                if(prefix < K){
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}