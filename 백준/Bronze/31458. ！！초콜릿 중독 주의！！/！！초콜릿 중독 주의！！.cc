#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string s;
        cin >> s;

        int len = s.length();
        bool flag = false;
        int rcnt = 0;
        int lcnt = 0;
        int num;
        for(int j = 0; j < len; j++){
            char v = s[j];
            if(v == '!' && !flag){
                rcnt++;
                continue;
            }
            if(v == '!' && flag){
                lcnt++;
                continue;
            }
            num = v - '0';
            flag = true;
        }

        if(lcnt >= 1){
            num = 1;
        }
        if(rcnt%2){
            if(num){
                cout << 0 << "\n";
            }
            if(!num){
                cout << 1 << "\n";
            }
        }
        if(!(rcnt%2)){
            cout << num << "\n";
        }
    }
    
    return 0;
}