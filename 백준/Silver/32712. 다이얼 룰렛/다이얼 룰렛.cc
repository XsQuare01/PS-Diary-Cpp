#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

int N, K;
long long arr[MAX+2];
long long lprefix[MAX+2] = {0, }; // 좌측으로!
long long rprefix[MAX+2] = {0, }; // 우측으로!
long long res = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        lprefix[i] = lprefix[i-1] + arr[i];
    }

    for(int i = N; i > 0; i--){
        rprefix[i] = rprefix[i+1] + arr[i];
    }

    for(int i = 1; i <= N; i++){
        long long tres1 = 0;
        if(i <= K){
            tres1 = lprefix[i] + (K - i) * arr[i];
        }
        long long tres2 = 0;
        if(N - i + 1 <= K){
            tres2 = rprefix[i] + (K - (N - i + 1)) * arr[i];
        }

        //Debug
        // cout << tres1 << " " << tres2 << "\n";

        res = max(res, max(tres1, tres2));
    }

    cout << res;
    return 0;
}
