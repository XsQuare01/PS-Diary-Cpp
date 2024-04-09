#define MAX 10000

#include<bits/stdc++.h>

using namespace std;

int N, R;
int arr[MAX + 1];
int dp[MAX + 1];
int carr[MAX + 1];
vector<int> varr[MAX + 1];
vector<int> rarr[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i] >> carr[i];
        for(int j = 1; j <= carr[i]; j++){
            int t2;
            cin >> t2;
            varr[i].push_back(t2);
            rarr[t2].push_back(i);
        }
    }

    for(int i = 1; i <= N; i++){
        if(carr[i] == 0){
            int tr = 0;
            for(auto a: varr[i]){
                tr = max(tr, dp[a]);
            }
            for(auto a: rarr[i]){
                carr[a]--;
            }
            dp[i] = arr[i] + tr;
            carr[i] = -1;
            R = max(R, dp[i]);
            continue;
        }
    }
    cout << R;
    return 0;
}