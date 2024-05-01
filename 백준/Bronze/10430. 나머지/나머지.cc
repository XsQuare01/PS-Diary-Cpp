#define MAX 48
#define INF 500000

#include<bits/stdc++.h>

using namespace std;

int A, B, C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;
    cout << (A + B) % C << "\n";
    cout << ((A % C) + (B % C)) % C<< "\n";
    cout << (A * B) % C << "\n";
    cout << ((A % C) * (B % C)) % C<< "\n";

    return 0;
}
 