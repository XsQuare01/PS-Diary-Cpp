#define MAX 200000
#define CMAX 100000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, k;
int arr[MAX];
int carr[CMAX + 1];
int res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int idx = 0, pidx = 0;
    while(idx < n){
        int v;
        while(true){
            if(idx >= n){
                cout << max(res, idx - pidx);
                return 0;
            }

            v = arr[idx++];
            carr[v]++;

            if(carr[v] > k){
                break;
            }
        }
        res = max(res, idx - pidx - 1);

        for(int i = pidx; i < idx; i++){
            int tv = arr[i];
            carr[tv]--;

            if(carr[v] > k){
                continue;
            }

            if(carr[v] <= k){
                pidx = ++i;
                break;
            }
        }
    }

    cout << res;
    return 0;

}