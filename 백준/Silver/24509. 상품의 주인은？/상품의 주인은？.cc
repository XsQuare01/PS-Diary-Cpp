#define MAX 1000000
#define MOD 1000000000
#define INF 200000

#include<bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[MAX];
pair<int, int> brr[MAX];
pair<int, int> crr[MAX];
pair<int, int> drr[MAX];
bool flag[MAX];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int x, a, b, c, d;
        cin >> x >> a >> b >> c >> d;

        arr[i] = {a, N-x};
        brr[i] = {b, N-x};
        crr[i] = {c, N-x};
        drr[i] = {d, N-x};
    }

    sort(arr, arr + N, greater<pair<int, int>>());
    sort(brr, brr + N, greater<pair<int, int>>());
    sort(crr, crr + N, greater<pair<int, int>>());
    sort(drr, drr + N, greater<pair<int, int>>());

    int idx = 0;
    while(flag[arr[idx].second]){
        idx++;
    }
    cout << -(arr[idx].second - N) << " ";
    flag[arr[idx].second] = true;

    idx = 0;
    while(flag[brr[idx].second]){
        idx++;
    }
    cout << -(brr[idx].second - N) << " ";
    flag[brr[idx].second] = true;

    idx = 0;
    while(flag[crr[idx].second]){
        idx++;
    }
    cout << -(crr[idx].second - N) << " ";
    flag[crr[idx].second] = true;

    idx = 0;
    while(flag[drr[idx].second]){
        idx++;
    }
    cout << -(drr[idx].second - N);


    return 0;
}