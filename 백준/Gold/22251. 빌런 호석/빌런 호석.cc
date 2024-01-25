#define MAX 10
#define DIGIT 7

#include<bits/stdc++.h>

using namespace std;
 
int arr[MAX][MAX];
int darr[MAX][DIGIT] = {
    {1, 1, 1, 0, 1, 1, 1},  // 0
    {0, 0, 1, 0, 0, 1, 0},  // 1
    {1, 0, 1, 1, 1, 0, 1},  // 2
    {1, 0, 1, 1, 0, 1, 1},  // 3
    {0, 1, 1, 1, 0, 1, 0},  // 4
    {1, 1, 0, 1, 0, 1, 1},  // 5
    {1, 1, 0, 1, 1, 1, 1},  // 6
    {1, 0, 1, 0, 0, 1, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};
int n, k, p, x;
int narr[6];
int res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            int cnt = 0;
            for(int k = 0; k < DIGIT; k++){
                if(darr[i][k] != darr[j][k]){
                    cnt++;
                }
            }
            arr[i][j] = cnt;
            arr[j][i] = cnt;
        }
    }
    cin >> n >> k >> p >> x;
    int u = x;
    for(int i = 1; i <= k; i++){
        narr[k-i] = u % 10;
        u /= 10;
    }
    for(int i = 1; i <= n; i++){
        int tarr[6];
        int u = i;
        for(int j = 1; j <= k; j++){
            tarr[k-j] = u % 10;
            u /= 10;
        }

        int cnt = 0;
        for(int j = 0; j < k; j++){
            int ncnt = narr[j];
            int tcnt = tarr[j];

            cnt += arr[ncnt][tcnt];
        }
        if(cnt <= p && cnt != 0){
            res++;
        }
    }

    cout << res;
    return 0;
}