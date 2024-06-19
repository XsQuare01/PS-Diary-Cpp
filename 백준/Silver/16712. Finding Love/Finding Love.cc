#define MAX 500

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX+1];
int varr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    arr[N] = -1;
    for(int i = 0; i < N-M+1; i++){
        cin >> varr[i];
    }
    for(int i = 0; i < N-M+1; i++){
        sort(arr, arr + M, less<int>());
        int v = varr[i]-1;
        arr[v] = arr[i+M];
    }
    for(int i = 0; i < M; i++){
        if(arr[i] == -1){
            continue;
        }
        cout << arr[i] << " ";
    }


    return 0;
}