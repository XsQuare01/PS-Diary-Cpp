#define MAX 500000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;
int r_cnt, b_cnt;
string s;
int res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;

    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            r_cnt++;
        }
        if(s[i] == 'B'){
            b_cnt++;
        }
    }
    res = min(r_cnt, b_cnt);

    int le = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            break;
        }
        le++;
    }
    int ri = 1;
    for(int i = n-2; i >= 0; i--){
        if(s[i+1] != s[i]){
            break;
        }
        ri++;
    }
    

    int tres;
    if(s[0] == s[n-1] && s[0] == 'R'){
        tres = min(r_cnt - le, r_cnt - ri);
    }

    if(s[0] == s[n-1] && s[0] == 'B'){
        tres = min(b_cnt - le, b_cnt - ri);
    }

    if(s[0] != s[n-1]){
        if(s[0] == 'R'){
            tres = min(r_cnt - le, b_cnt - ri);
        }
        if(s[0] == 'B'){
            tres = min(b_cnt - le, r_cnt - ri);
        }
    }
    res = min(res, tres);

    cout << res;
    return 0;

}