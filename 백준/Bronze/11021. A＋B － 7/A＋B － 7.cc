#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << "\n";
    }

    return 0;
}
 