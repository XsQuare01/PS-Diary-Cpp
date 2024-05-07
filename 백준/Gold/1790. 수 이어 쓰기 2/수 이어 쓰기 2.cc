#define MAX 2222
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, K;
long long len, plen;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> N >> K;

    int tn = N;
    int cnt = 1;
    long long pcnt = 1;

    while(pcnt <= N){
        plen = len;
        len += 9 * pcnt * cnt;
        if(K <= len){
            break;
        }
        cnt++;
        pcnt *= 10;
    }

    if(K > len){
        cout << -1;
        return 0;
    }
    //Debug
    // cout << cnt << " " << pcnt << " " << len << " " << plen << endl;

    K -= 1;
    long long share = (K - plen) / cnt;
    long long remain = (K - plen) % cnt;
    // cout << share << " " << remain << endl;

    long long num = pcnt + share;
    if(num > N){
        cout << -1;
        return 0;
    }
    // cout << num << endl;
    string snum = to_string(num);
    cout << snum[remain];
    return 0;
}