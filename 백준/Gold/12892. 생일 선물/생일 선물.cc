#define MAX 1000000
#define INF 9223372036854775807

#include<bits/stdc++.h>

using namespace std;

int N, D;
pair<long long, long long> arr[MAX + 1];
long long prefix[MAX + 1];
long long res = -1;

int BinarySearch(long long val){
    int st = 0;
    int ed = N;
    int mid;
    while(st < ed){
        int mid = (st + ed) / 2;
        long long mid_val = arr[mid].first;

        if(mid_val == val){
            return mid;
        }
        if(mid_val < val){
            st = mid + 1;
            continue;
        }
        if(mid_val > val){
            ed = mid;
            continue;
        }
    }
    return st;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> D;
    for(int i = 0; i < N; i++){
        long long tp, tv;
        cin >> tp >> tv;
        arr[i] = {tp, tv};
    }
    sort(arr, arr+N, less<pair<long long, long long>>());

    for(int i = 1; i <= N; i++){
        prefix[i] = prefix[i-1] + arr[i-1].second;
    }    

    for(int i = 0; i < N; i++){
        long long val = arr[i].first + D;
        int idx = BinarySearch(val);

        long long t_res = prefix[idx] - prefix[i];
        res = max(res, t_res);
    }
    cout << res;
    return 0;
}