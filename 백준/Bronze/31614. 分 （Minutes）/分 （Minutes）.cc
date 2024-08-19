#define MAX 200000
#define MOD 13

#include<bits/stdc++.h>

using namespace std;

int H, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> M;
    cout << H*60+M;
    return 0;
}