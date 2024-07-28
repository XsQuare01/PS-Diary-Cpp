#define NMAX 100
#define MMAX 10
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

string S1, S2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S1 >> S2;
    if(S1.length() < S2.length()){
        cout << "no";
    }
    else{
        cout << "go";
    }

    return 0;
}   