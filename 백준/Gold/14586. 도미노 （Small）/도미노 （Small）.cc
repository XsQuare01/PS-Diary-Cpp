#define MAX 300
#define INF 987654321

// https://www.acmicpc.net/problem/14586

#include<bits/stdc++.h>

using namespace std;

int n;
pair<long long, long long> parr[MAX];
int larr[MAX][MAX];
int rarr[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        long long x, h;
        cin >> x >> h;
        parr[i] = {x, h};
    }

    sort(parr, parr + n);

    //Debug
    // for(int i = 0; i < n; i++){
    //     cout << parr[i].first << " " << parr[i].second << endl;
    // }
    // cout << endl;

    for(int i = 0; i < n; i++){
        int cnt = 1;
        long long height = parr[i].first;
        for(int j = i; j < n; j++){
            long long x = parr[j].first;
            long long h = parr[j].second;

            if(height < x){
                larr[i][j] = ++cnt;
                height = x + h;
                continue;
            }
            larr[i][j] = cnt;
            height = max(height, x + h);
        }
    }

    for(int i = n - 1; i >= 0; i--){
        int cnt = 1;
        long long height = parr[i].first;
        for(int j = i; j >= 0; j--){
            long long x = parr[j].first;
            long long h = parr[j].second;

            if(height > x){
                rarr[i][j] = ++cnt;
                height = x - h;
                continue;
            }
            rarr[i][j] = cnt;
            height = min(height, x - h);
        }
    }

    int res = min(larr[0][n-1], rarr[n-1][0]);
    for(int i = 1; i < n-1; i++){
        res = min(res, larr[i][n - 1] + rarr[i - 1][0]);
        res = min(res, larr[0][i - 1] + rarr[n - 1][i]);
    }
    cout << res;

    return 0;
}