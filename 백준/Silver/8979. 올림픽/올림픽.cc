#define MAX 1000
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int n, k;
pair<pair<pair<int, int>, int>, int> arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int t1, t2, t3, t0;
        cin >> t0 >> t1 >> t2 >> t3;
        arr[i] = {{{t1, t2}, t3}, t0};
    }

    sort(arr, arr+n);
    pair<pair<int, int>, int> prev = {{-1, -1}, -1};
    int rank = -1;
    for(int i = 0; i < n; i++){
        auto rat = arr[i].first;
        if(rat != prev){
            rank = i + 1;
            prev = rat;
        }

        if(arr[i].second == k){
            cout << rank;
            break;
        }
    }

    return 0;   
}
