#define MAX 500000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX];
int res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    res = N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int cnt = 1;
    for(int i = 0; i < N; i++){
        if(cnt + arr[i] >= res){
            break;
        }

        res -= 1;
        cnt += arr[i];

    }

    cout << res-1;
    return 0;
}