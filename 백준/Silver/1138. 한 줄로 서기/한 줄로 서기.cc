#define MAX 10

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[MAX + 1];
int res[MAX + 1] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        int v = arr[i];
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(cnt == v && !res[j]){
                res[j] = i;
                break;
            }

            if(res[j] > i || !res[j]){
                cnt++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}