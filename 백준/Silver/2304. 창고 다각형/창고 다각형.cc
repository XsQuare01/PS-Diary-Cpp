#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[MAX + 1];
int larr[MAX + 1];
int rarr[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        int idx, h;
        cin >> idx >> h;
        arr[idx] = h;
    }
    
    larr[MAX] = arr[MAX];
    for(int i = MAX - 1; i >= 0; i--){
        larr[i] = max(larr[i + 1], arr[i]);
    }
    for(int i = 1; i <= MAX; i++){
        rarr[i] = max(rarr[i-1], arr[i]);
    }

    int res = 0;
    for(int i = 1; i <= MAX; i++){
        res += min(rarr[i], larr[i]);
    }
    cout << res;
    return 0;
}