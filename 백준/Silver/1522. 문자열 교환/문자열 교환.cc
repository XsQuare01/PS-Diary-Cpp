#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string s;
int len, a_cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;
    len = s.length();

    for(int i = 0; i < len; i++){
        if(s[i] == 'a'){
            a_cnt++;
        }
    }
    int res = INF;

    for(int i = 0; i < len; i++){
        int idx = i;
        int b_cnt = 0;
        for(int j = 0; j < a_cnt; ){
            if(idx == len){
                idx = 0;
                continue;
            }

            if(s[idx] == 'b'){
                b_cnt++;
            }
            idx++;
            j++;
        }

        res = min(res, b_cnt);
    }
    cout << res;

    return 0;
}