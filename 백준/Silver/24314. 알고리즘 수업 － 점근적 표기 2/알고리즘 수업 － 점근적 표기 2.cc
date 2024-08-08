#define MAX 50
#define MOD 1000000009

#include<bits/stdc++.h>

using namespace std;

int A0, A1;
int C;
int N0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A0 >> A1 >> C >> N0;
    if(A0 >= C && A0 * (N0+1) + A1 >= C * (N0+1)){
        cout << 1;
    }
    else{
        cout << 0;
    }

    return 0;
}