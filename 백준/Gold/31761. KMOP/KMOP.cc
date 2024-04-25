#define MAX 1000000
#define LEN 3
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int N;
string arr[MAX];
char darr[6] = { 'A', 'E', 'I', 'O', 'U', 'Y'};
int dp[LEN];

int CountFrontConsonant(int idx, int len){
    int ret = 0;
    for(int i = 0; i <= len; i++){
        for(auto a: darr){
            if(a == arr[idx][i]){
                return ret;
            }
        }
        ret++;
    }
    return ret;
}

int CountBackConsonant(int idx, int len){
    int ret = 0;
    for(int i = 0; i <= len; i++){
        ret++;
        for(auto a: darr){
            if(a == arr[idx][i]){
                ret = 0;
            }
        }
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    //Init
    for(int i = 0; i < LEN; i++){
        dp[i] = INF;
    }
    int s_len = arr[0].length();
    s_len = min(s_len, LEN);
    for(int i = 0; i < s_len; i++){
        int cnt = CountBackConsonant(0, i);
        dp[cnt] = min(i + 1, dp[cnt]);
    }

    //Debug
    // for(int tp = 0; tp < LEN; tp++){
    //     cout << tp << " " << dp[tp] << endl;
    // }
    // cout << endl;

    for(int i = 1; i < N; i++){ // i번째 문자열
        int tdp[LEN];
        for(int j = 0; j < LEN; j++){
            tdp[j] = INF;
        }

        int s_len = arr[i].length();
        s_len = min(s_len, LEN);

        for(int j = 0; j < s_len; j++){   // 글자 수
            int cnt = CountFrontConsonant(i, j);

            for(int k = 0; k < LEN; k++){   // 연속된 자음의 개수
                int len;
                if(cnt == j + 1){
                    len = cnt + k;
                }
                else if(cnt != j + 1){
                    len = CountBackConsonant(i, j);
                }
                if(cnt + k >= LEN){
                    continue;
                }
                if(len >= LEN){
                    continue;
                }
                
                int cur = dp[k];
                if(cnt >= INF){
                    continue;
                }

                tdp[len] = min(tdp[len], cur + j + 1);
            }
        }



        for(int j = 0; j < LEN; j++){
            // if(tdp[j] >= INF){
            //     continue;
            // }
            dp[j] = tdp[j];
        }

        //Debug
        // for(int tp = 0; tp < LEN; tp++){
        //     cout << tp << " " << dp[tp] << endl;
        // }
        // cout << endl;


    }

    int res = INF;
    for(int i = 0; i < LEN; i++){
        res = min(res, dp[i]);
    }

    if(res >= INF){
        cout << '*';
    }
    else{
        cout << res;
    }
    return 0;
}