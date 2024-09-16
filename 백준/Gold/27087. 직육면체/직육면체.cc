#define MAX 1000000
#define MOD 9901
#define INF 200000

#include<bits/stdc++.h>

using namespace std;

int T;
int A, B, C, P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> A >> B >> C >> P;
        int cnt = 0;
        if(A % P == 0){
            cnt++;
        }
        if(B % P == 0){
            cnt++;
        }
        if(C % P == 0){
            cnt++;
        }

        if(cnt >= 2){
            cout << 1 <<"\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}