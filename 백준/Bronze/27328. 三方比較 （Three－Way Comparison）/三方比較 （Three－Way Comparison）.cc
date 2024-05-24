#define MAX 10000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int A, B;
int res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B;
    if(A == B){
        res = 0;
    }
    if(A != B){
        res = A > B ? 1 : -1;
    }
    cout << res;
    
    return 0;
}