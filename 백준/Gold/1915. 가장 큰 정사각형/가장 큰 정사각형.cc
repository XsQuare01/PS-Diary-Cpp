#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[MAX][MAX];
pair<int, int> parr[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    parr[0][0] = {arr[0][0], arr[0][0]};

    for(int i = 1; i < n; i++){
        int tx = parr[0][i-1].first;
        if(arr[0][i]){
            parr[0][i] = {1 + tx, 1};
        }
    }
    for(int i = 1; i < n; i++){
        int ty = parr[i-1][0].second;
        if(arr[i][0]){
            parr[i][0] = {1, 1 + ty};
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(!arr[i][j]){
                continue;
            }

            int tx = min(min(parr[i][j-1].first, parr[i-1][j].first), parr[i-1][j-1].first);
            int ty = min(min(parr[i][j-1].second, parr[i-1][j].second), parr[i-1][j-1].second);

            parr[i][j] = {tx + 1, ty + 1};
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!arr[i][j]){
                continue;
            }

            if(parr[i][j].first == parr[i][j].second){
                res = max(res, parr[i][j].first);
            }
        }
    }

    cout << res * res << "\n";
    return 0;   
}
