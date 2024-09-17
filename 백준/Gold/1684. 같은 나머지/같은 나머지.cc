#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX];   
int term = INF;

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    return GCD(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int prev = arr[0];
    term = arr[1] - arr[0];
    for(int i = 2; i < N; i++){
        int tres = GCD(term, arr[i] - prev);
        term = tres;
        prev = arr[i];
    }
    cout << term;
    
    return 0;
}