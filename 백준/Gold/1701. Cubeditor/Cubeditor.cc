#define MAX 100000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string S;
vector<int> pi;
int res = 0;

void FindPI(string str){
    pi = vector<int>();

    int len = str.length();
    int idx = 0;
    pi.push_back(0);
    for(int i = 1; i < len; i++){
        while(idx && str[i] != str[idx]){
            idx = pi[idx - 1];
        }
        if(str[i] == str[idx]){
            pi.push_back(++idx);
            res = max(res, idx);
        }
        else{
            pi.push_back(0);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    int len = S.length();
    for(int i = 0; i < len; i++){
        string str = S.substr(i, len);
        FindPI(str);
    }
    

    cout << res;
    return 0;
}