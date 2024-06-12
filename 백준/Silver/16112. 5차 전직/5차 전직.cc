#define MAX 300000

#include<bits/stdc++.h>

using namespace std;

int N, K;
long long arr[MAX];
long long res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N, less<int>());
    for(int i = 0; i < K; i++){
        res += (arr[i] * i); 
    }
    for(int i = K; i < N; i++){
        res += (arr[i] * K);
    }
    cout << res;


    return 0;
}