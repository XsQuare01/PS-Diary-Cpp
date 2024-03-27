#define MAX 100
#define AMAX 27
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string S;
string arr[MAX];
vector<int> varr[AMAX];
int dp[MAX][MAX];
int N;

int StringMatch(int sidx, string t, int tidx){
    int ret = 0;
    if(dp[sidx][tidx] != -1){
        return dp[sidx][tidx];
    }
    if(S[sidx] == '*'){
        while(S[sidx] == '*'){
            dp[sidx][tidx] = 1;
            sidx++;
        }
        if(S[sidx]){
            for(int i = tidx; t[i]; i++){
                if(S[sidx] == t[i]){
                    // cout << "S[sidx]: " << S[sidx] << " " << i << endl;
                    dp[sidx][i] = StringMatch(sidx, t, i);
                    ret |= dp[sidx][i];
                }
            }
            return ret;
        }
        if(!S[sidx]){
            return 1;
        }
    }
    if(S[sidx] != '*'){
        if(S[sidx] != t[tidx]){
            return 0;
        }
        if(!S[sidx+1] && tidx == t.length()-1){
            return 1;
        }
        int c;
        if(S[sidx] == '.'){
            c = 26;
        }
        if(S[sidx] != '.'){
            c = S[sidx] - 'a';
        }
        for(auto a: varr[c]){
            if(a < tidx){
                continue;
            }
            if(a >= tidx){
                dp[sidx+1][a+1] = StringMatch(sidx+1, t, a+1);
                ret |= dp[sidx+1][a+1];
            }
        }
        return ret;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S >> N;
    for(int i = 0; i < N; i++){
        // Init
        for(int j = 0; j < AMAX; j++){
            varr[j] = vector<int>();
        }
        for(int j = 0; j < MAX; j++){
            for(int k = 0; k < MAX; k++){
                dp[j][k] = -1;
            }
        }
        cin >> arr[i];
        for(int j = 0; arr[i][j]; j++){
            int idx;
            if(arr[i][j] == '.'){
                idx = 26;
            }
            if(arr[i][j] != '.'){
                idx = arr[i][j] - 'a';
            };
            varr[idx].push_back(j);
        }
        if(StringMatch(0, arr[i], 0)){
            cout << arr[i] << "\n";
        }
    }
    return 0;
}
