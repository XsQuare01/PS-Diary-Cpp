#define MAX 100000
#define HMAX 500000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, h;
int uarr[MAX + 2];
int darr[MAX + 2];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> h;
    for(int i = 0; i < n; i++){
        if(i%2){
            int t;
            cin >> t;
            uarr[i/2] = h - t;
        }
        if(!(i%2)){
            cin >> darr[i/2];
        }
    }
    uarr[n/2] = INF;
    darr[n/2] = INF;
    sort(uarr, uarr + n/2 + 1);
    sort(darr, darr + n/2 + 1);
    

    int res = 0;
    int minimum = INF;
    for(int i = 1; i <= h; i++){
        int uidx = lower_bound(uarr, uarr + n/2, i) - uarr;
        int didx = lower_bound(darr, darr + n/2, i) - darr;

        int sum = n/2 + uidx - didx;
        if(sum < minimum){
            minimum = sum;
            res = 1;
            continue;
        }
        if(sum == minimum){
            res++;
        }
    }
    cout << minimum << " " << res;

    return 0;
}
