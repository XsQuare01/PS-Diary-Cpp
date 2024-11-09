#define MAX 1000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

long long N;
int res = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    if(N == 0){
        res = 0;
    }
    else if(N == 1 || N == -1){
        res = 1;
    }
    else if(N % 2){
        double tres = log2(abs(N));
        res = ceil(tres);
    }
    cout << res;

    return 0;
}