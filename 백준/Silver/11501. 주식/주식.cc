#define MAX 1000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int T;
int arr[MAX];
int larr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    for(int i = 0; i < T; i++){
        long long res = 0;
        int n;
        cin >> n;
        
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        larr[n-1] = arr[n-1];
        for(int j = n-2; j >= 0; j--){
            larr[j] = max(larr[j + 1], arr[j]);
            res += (larr[j] - arr[j]);
        }
        cout << res << "\n";
    }

    return 0;

}