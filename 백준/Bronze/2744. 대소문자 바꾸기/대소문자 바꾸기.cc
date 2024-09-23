#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    int len = S.length();
    for(int i = 0; i < len; i++){
        char c = S[i];
        if(c >= 'a' && c < 'z'){
            cout << (char)(c - 'a' + 'A');
        }
        else{
            cout << (char)(c - 'A' + 'a');
        }
    }

    return 0;
}