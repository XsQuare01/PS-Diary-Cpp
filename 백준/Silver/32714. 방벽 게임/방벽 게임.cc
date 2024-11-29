#include <bits/stdc++.h>
#define MAX 5000

using namespace std;

int N;
int res = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    if(N == 2){
        res = 1;
    }
    else if(N == 3){
        res = 3;
    }
    else{
        res = 3 * N - 4;
    }
    

    cout << res;

    return 0;
}
