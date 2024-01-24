#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;
pair<int, int> arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        int t, s;
        cin >> t >> s;
        arr[i] = {s, t};
    }

    sort(arr, arr + n);

    int sum = 0;
    int res = INF;
    for(int i = 0; i < n; i++){

        int s = arr[i].first;
        int t = arr[i].second;
        sum += t;

        if(sum > s){
            cout << -1;
            return 0;
        }
        res = min(res, s - sum);
    }
    cout << res;
    return 0;
}