#define MAX 30000
#define DMAX 3000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, d, k, c;
int arr[MAX];
int darr[DMAX + 1];
int cnt, res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < k; i++){
        int v = arr[i];
        darr[v]++;
        if(darr[v] == 1){
            res++;
        }
    }

    if(!darr[c]){
        darr[c]++;
        res++;
    }
    cnt = res;

    for(int i = 1; i < n; i++){
        int pidx = (i - 1) % n;
        int pv = arr[pidx];

        int nidx = (i + k - 1) % n;
        int nv = arr[nidx];

        darr[pv]--;
        if(darr[pv] == 0){
            cnt--;
        }
        darr[nv]++;
        if(darr[nv] == 1){
            cnt++;
        }

        if(!darr[c]){
            res = max(res, cnt + 1);
        }
        if(darr[c]){
            res = max(res, cnt);
        }
    }
    cout << res;
    return 0;

}