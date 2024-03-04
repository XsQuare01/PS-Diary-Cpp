#define MAX 31
#define HMAX 500000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

long long arr[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < MAX; i++){
        arr[0][i] = 1;
    }
    for(int i = 1; i < MAX; i++){
        for(int j = i; j < MAX; j++){
            arr[i][j] = arr[i][j-1] + arr[i-1][j];
        }
    }

    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        cout << arr[n][n] << "\n";
    }

    return 0;
}
