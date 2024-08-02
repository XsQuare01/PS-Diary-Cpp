#define MAX 100
#define INF 1000000000
#define PI 3.141592653589793

#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> varr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 5; i <= INF; i *= 5){
        varr.push_back(i);
    }

    cin >> T;
    for(int i = 0; i < T; i++){
        int n, res = 0;   
        cin >> n;
        for(auto a: varr){
            res += (n / a);
        }
        cout << res << "\n";
    }

    return 0;
}