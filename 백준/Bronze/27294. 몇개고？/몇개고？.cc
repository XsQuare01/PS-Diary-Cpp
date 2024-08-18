#define MAX 1000
#define MOD 13

#include<bits/stdc++.h>

using namespace std;

int T, S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T >> S;
    if(S || T <= 11 || T >= 17){
        cout << 280;
    }
    else{
        cout << 320;
    }
    return 0;
}