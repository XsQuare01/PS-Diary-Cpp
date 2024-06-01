#define MOD 1000000007
#define MAX 100000

#include<bits/stdc++.h>

using namespace std;

int N;
long long darr[MAX];
long long parr[MAX];
long long R;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N-1; i++){
        cin >> darr[i];
    }
    for(int i = 0; i < N; i++){
        cin >> parr[i];
    }
    for(int i = 1; i < N; i++){
        parr[i] = min(parr[i], parr[i-1]);
    }
    for(int i = 0; i < N-1; i++){
        R += darr[i] * parr[i];
    }
    cout << R;

    return 0;
}