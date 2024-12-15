#include <bits/stdc++.h>
#define MAX 100000
#define INF 210000000000
#define MOD 998244353

using namespace std;

int N;
int carr[MAX];

int larr[MAX];
long long lprefix[MAX];

int rarr[MAX];
long long rprefix[MAX];

long long res = INF;
int idx = -1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> carr[i];
    }
    for(int i = 1; i < N; i++){
        cin >> larr[i];
        lprefix[i] = lprefix[i-1] + larr[i];
    }
    for(int i = 1; i < N; i++){
        cin >> rarr[i];
        rprefix[i] = rprefix[i-1] + rarr[i];
    }

    for(int i = 0; i < N; i++){
        long long tsum = 0;
        long long lsum = lprefix[i];
        long long rsum = rprefix[N-1] - rprefix[i];

        tsum = lsum + rsum + carr[i];

        if(tsum < res){
            res = tsum;
            idx = i;
        }
    }

    cout << idx + 1 << " "<< res << " ";
    return 0;
}
