#define MAX 100000

#include<bits/stdc++.h>

using namespace std;

int N, M;
int maximum = 0;
int arr[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> arr[i];
    }

    maximum = max(arr[0], N - arr[M-1]);
    for(int i = 1; i <= M; i++){
        int t = ceil(1.0 * (arr[i] - arr[i-1]) / 2);
        maximum = max(maximum, t);
    }
    cout << maximum;

    return 0;
}