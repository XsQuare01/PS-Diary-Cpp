#define MAX 5000

#include <bits/stdc++.h>

using namespace std;

int N, K, idx, cnt = 0;
bool arr[MAX] = {false, };
bool f = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    cout << "<";
    idx = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; idx++){
            if(idx >= N){
                idx %= N;
            }
            if(arr[idx]){
                continue;
            }
            j++;
        }
        
        if(f){
            cout << ", ";
        }
        arr[idx-1] = true;
        f = true;
        cout << idx;
    }
    cout << ">";
    return 0;
}