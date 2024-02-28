#define MAX 10000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

long long n, k;
long long st, ed;
long long arr[MAX];

long long Divider(int v){
    long long res = 0;
    for(int i = 0; i < k; i++){
        res += (arr[i] / v);
    }
    return res;
}

int BinarySearch(){
    int mid;
    while(st < ed){
        mid = (st + ed) / 2;
        long long mres = Divider(mid);

        if(mres >= n){
            st = mid;
        }
        if(mres < n){
            ed = mid - 1;
        }

        long long eres = Divider(ed);
        if(eres >= n){
            return ed;
        }
        if(eres < n){
            ed--;
        }
    }
    return ed;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    st = 1;
    ed = 1;
    for(int i = 0; i < k; i++){
        cin >> arr[i];
        ed = max(ed, arr[i]);
    }

    cout << BinarySearch();
}
