#define MAX 1000000

#include<bits/stdc++.h>

using namespace std;

int N;
long long G, H, R;
int arr[MAX];

int CuttingNumber(int n){
    while(n > 9){
        int res = 0;
        for(; n > 0; n /= 10){
            res += n % 10;
        }
        n = res;
    }

    return n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr[i] = CuttingNumber(arr[i]);
    }
    G = arr[N-1]; H = 1; R = arr[N-1];
    for(int i = N-2; i >= 0; i--){
        int th = CuttingNumber(H + G);
        int tres = CuttingNumber(arr[i] * th);

        H = th;
        G = tres;
        R = CuttingNumber(R + G);
    }

    cout << R;


    return 0;
}