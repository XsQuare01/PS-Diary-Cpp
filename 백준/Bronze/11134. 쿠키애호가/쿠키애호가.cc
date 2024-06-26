#define MAX 50
#define LEN 50

#include<bits/stdc++.h>

using namespace std;

int T, N, C, R;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> C;
        R = ceil(1.0 * N / C);
        cout << R << "\n";
    }
    return 0;
}
 