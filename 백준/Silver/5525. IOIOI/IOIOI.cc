#define MAX 100000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string S, P;
int N, M;
int K, res = 0;
vector<int> pi;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> S;

    P = "I";
    pi.push_back(0);

    for(int i = 1; i <= N; i++){
        P += "OI";
        int p1 = 2 * i - 2;
        int p2 = 2 * i - 1;
        if(p1 <= 0){
            pi.push_back(0);
        }
        else{
            pi.push_back(p1);
        }
        pi.push_back(p2);
    }

    int plen = 2 * N + 1;
    int idx = 0;
    for(int i = 0; i < M; i++){
        while(idx && S[i] != P[idx]){
            idx = pi[idx - 1];
        }

        if(S[i] == P[idx]){
            if(++idx == plen){
                res++;
                idx = pi[idx - 1];
            }
        }
    }

    cout << res;
    return 0;
}