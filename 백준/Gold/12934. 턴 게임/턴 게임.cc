#define NMAX 100
#define MMAX 10
#define INF 2147483647
#define PI 3.141592653589793

#include <bits/stdc++.h>

using namespace std;

long long X, Y, S;
long long t_sum = 0, cnt = 0;
int res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y;
    S = X + Y;
    while(t_sum < S){
        t_sum += (cnt+1);
        cnt++;
    }

    if(t_sum > S){
        cout << -1;
        return 0;
    }
    else if(t_sum == S){
        while(X >= cnt && cnt > 0){
            X -= cnt;
            cnt--;
            res++;
        }
        if(X){
            res++;
        }
        cout << res;
    }
    
    return 0;
}   