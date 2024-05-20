#define MAX 10000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX + 2];
int pfix = 0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        arr[t + 1]++;
    }
    for(int i = 1; i <= N; i++){
        pfix += arr[i];
        if(pfix >= i){
            cout << i;
            break;
        }
    }
    
    return 0;
}