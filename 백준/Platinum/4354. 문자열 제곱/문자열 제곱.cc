#define MAX 100
#define MOD 1000000007
#define INF 10000000

#include<bits/stdc++.h>

using namespace std;

string S;
int len;
vector<int> pi;

void getPI(){
    pi.push_back(0);
    int idx = 0;
    for(int i = 1; i < len; i++){
        while(idx && S[i] != S[idx]){
            idx = pi[idx - 1];
        }

        if(S[i] == S[idx]){
            pi.push_back(++idx);
        }
        else{
            pi.push_back(0);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> S;
        if(S == "."){
            break;
        }
        pi = vector<int>();
        len = S.length();

        getPI();
        int pattern_len = len - pi[len - 1];

        if(len % pattern_len){
            cout << 1 << "\n";
        }
        else{
            int res = len / pattern_len;
            cout << res << "\n";
        }
    }

    return 0;
}