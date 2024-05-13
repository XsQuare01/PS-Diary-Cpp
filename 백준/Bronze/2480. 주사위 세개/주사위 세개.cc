#define MAX 6

#include<bits/stdc++.h>

using namespace std;

int A, B, C;
int res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> A >> B >> C;
    
    if(A == B && B == C){
        res = 10000 + A * 1000;
    }
    else if(A != B && B != C && C != A){
        int t = max(max(A, B), C);
        res = 100 * t;
    }
    else if(A == B){
        res = 1000 + A * 100;
    }
    else if(B == C){
        res = 1000 + B * 100;
    }
    else if(A == C){
        res = 1000 + C * 100;
    }
    cout << res;
    return 0;
}