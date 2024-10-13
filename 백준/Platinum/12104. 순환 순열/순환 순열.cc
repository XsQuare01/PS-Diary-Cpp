#define MAX 100000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int len, res = 0;
string A, B;
vector<int> pi;

void GetPi(){
    int idx = 0;
    pi.push_back(0);
    for(int i = 1; i < len; i++){
        while(idx && A[i] != A[idx]){
            idx = pi[idx - 1];
        }

        if(A[i] == A[idx]){
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

    cin >> A >> B;
    len = B.length();

    string s = B.substr(0, len-1);
    B += s;

    GetPi();

    int idx = 0;
    for(int i = 0; i < 2 * len - 1; i++){
        while(idx && B[i] != A[idx]){
            idx = pi[idx - 1];
        }

        if(B[i] == A[idx]){
            if(idx == len - 1){
                res++;
                idx = pi[idx - 1];
            }
            ++idx;
        }
    }

    cout << res;

    return 0;
}