#define MAX 500000
#define MOD 1000000007
#define INF 26

#include<bits/stdc++.h>

using namespace std;

int N;

long long arr[MAX];
long long sum = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N, less<int>());

    int t = -N + 1;
    for(int i = 0; i < N; i++){
        sum += t * arr[i];
        t += 2;
    }

    cout << sum * 2;


    return 0;
}