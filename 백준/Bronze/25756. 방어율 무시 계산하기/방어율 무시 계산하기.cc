#define MAX 40000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    double v = 0.0;
    for(int i = 0; i < n; i++){
        double a;
        cin >> a;
        v = 100 - (1 - v / 100) * (1 - a / 100) * 100;
        printf("%lf\n", v);
        // cout << round(v * 1000000) / 1000000 << "\n";
    }

    
    return 0;

}