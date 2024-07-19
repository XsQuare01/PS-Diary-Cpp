#define MAX 100
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int N;
char maximum = -1;
vector<char> varr[MAX+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    if(N <= 2){
        cout << 1;
    }
    else if(N <= 5){
        cout << 2;
    }
    else{
        cout << 3;
    }
    return 0;
}   