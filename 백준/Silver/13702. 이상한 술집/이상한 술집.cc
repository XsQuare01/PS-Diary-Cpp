#define MAX 10000
#define MOD 1000000007
#define INF 2147483647

#include<bits/stdc++.h>

using namespace std;

int N, K;
int arr[MAX];

long long binarySearch(){
    int st = 0;
    int ed = INF;

    while(st < ed){
        long long mid = (0LL + st + ed) / 2;
        int cnt = 0;

        for(int i = 0; i < N; i++){
            int t = arr[i] / mid;
            cnt += t;
        }

        if(cnt >= K){
            st = mid+1;
        }
        else if(cnt < K){
            ed = mid;
        }
    }
    
    return st;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    long long res = binarySearch();
    cout << res-1;
    return 0;
}