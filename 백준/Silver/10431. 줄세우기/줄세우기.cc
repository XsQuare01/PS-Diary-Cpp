#define MAX 20
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;
        int res = 0;
        for(int j = 0; j < MAX; j++){
            cin >> arr[j];
            for(int k = 0; k < j; k++){
                if(arr[k] > arr[j]){
                    res++;
                }
            }
        }

        cout << n << " " << res << "\n";
    }
    return 0;   
}
