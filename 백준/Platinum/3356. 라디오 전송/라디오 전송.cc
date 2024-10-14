#define MAX 100000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int L;
string S;
vector<int> pi;

void getPi(){
    int idx = 0;
    pi.push_back(0);
    for(int i = 1; i < L; i++){
        while(idx  && S[i] != S[idx]){
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

    cin >> L >> S;
    getPi();
    cout <<  L - pi[L-1];


    return 0;
}