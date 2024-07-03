#define MAX 200000
#define INF 2147483648

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int idx, s, e;
        cin >> idx >> s >> e;

        if(arr[idx] > s){
            cout << "NO" << "\n";
            continue;
        }
        arr[idx] = e;
        cout << "YES" << "\n";
        
    }

    return 0;
}