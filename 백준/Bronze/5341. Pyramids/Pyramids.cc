
#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while(N){
        cout << N * (N+1) / 2 <<"\n";
        cin >> N;
    }

    return 0;
}
 