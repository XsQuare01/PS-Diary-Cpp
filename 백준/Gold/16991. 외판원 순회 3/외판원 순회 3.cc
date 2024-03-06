#define MAX 16
#define PMAX 131072
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int n;
int ridx = 1;
double res = INF;
pair<int, int> carr[MAX];
double arr[MAX][MAX];
int parr[MAX];
double dp[MAX][PMAX];
double cp[MAX][PMAX];
queue<int> q;

double CalcDist(int y1, int y2, int x1, int x2){
    return sqrt(pow(1.0 * y2 - y1, 2) + pow(1.0 * x2 - x1, 2));
}

int BitMask(int u, int v){
    return u + parr[v];
}

void BitCheck(int idx){
    for(int i = n-1; i >= 0; i--){
        if(idx / parr[i]){
            idx %= parr[i];
            continue;
        }
        q.push(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // Input
    cin >> n;
    for(int i = 0; i < n; i++){
        int ty, tx;
        cin >> ty >> tx;
        carr[i] = {ty, tx};
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                arr[i][j] = -1;
                continue;
            }
            double d = CalcDist(carr[i].first, carr[j].first, carr[i].second, carr[j].second);
            arr[i][j] = d;
        }
    }


    // Init
    parr[0] = 1;
    for(int i = 1; i < n; i++){
        parr[i] = 2 * parr[i-1];
        ridx += parr[i];
    }

    // st -> i
    for(int i = 0; i < n; i++){
        if(arr[0][i] == -1){
            continue;
        }
        int idx = parr[0] + parr[i];
        if(dp[i][idx]){
            dp[i][idx] = min(dp[i][idx], arr[0][i]);
            continue;
        }
        dp[i][idx] = arr[0][i];
    }

    for(int i = 3; i <= n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 1; k <= ridx; k++){
                if(!dp[j][k]){
                    continue;
                }
                BitCheck(k);

                while(!q.empty()){
                    int v = q.front();
                    q.pop();

                    if(!arr[j][v]){
                        continue;
                    }

                    int idx = BitMask(k, v);
                    if(cp[v][idx]){
                        cp[v][idx] = min(cp[v][idx], dp[j][k] + arr[j][v]);
                        continue;
                    }
                    cp[v][idx] = dp[j][k] + arr[j][v];
                }
            }
        }

        for(int j = 0; j < n; j++){
            for(int k = 1; k <= ridx; k++){
                dp[j][k] = cp[j][k];
            }
        }
    }


    for(int i = 0; i < n; i++){
        if(!dp[i][ridx]){
            continue;
        }

        if(!arr[i][0]){
            continue;
        }
        res = min(res, dp[i][ridx] + arr[i][0]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 1; k<= ridx; k++){
                dp[j][k] = 0;
                cp[j][k] = 0;
            }
        }
    }
    cout << res;
    return 0;   
}
