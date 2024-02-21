#define MAX 100000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, m;
string arr[MAX];
int parr[MAX];

int BinarySearch(int st, int ed, int v){
    int mid;
    while(st < ed){
        mid = (st + ed) / 2;
        if(parr[mid] >= v){
            ed = mid;
            continue;
        }

        if(parr[mid] < v){
            st = mid + 1;
            continue;
        }
    }
    return st;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i] >> parr[i];
        
    }

    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        int idx = BinarySearch(0, n-1, t);
        cout << arr[idx] << "\n";
    }

    
    return 0;

}