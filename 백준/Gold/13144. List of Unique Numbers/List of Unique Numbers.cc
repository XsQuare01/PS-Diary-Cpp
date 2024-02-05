#define MAX 100000

#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[MAX + 1];
bool flag[MAX + 1];
long long res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int prev = 0;
    for(int i = 0; i < n; i++){
        int u = arr[i];
        for(int j = prev; j < n; j++, prev++){
            int v = arr[j];
            if(flag[v]){
                break;
            }
            flag[v] = true;
        }
        res += (prev - i);
        flag[u] = false;
    }

    cout << res;
    return 0;
}