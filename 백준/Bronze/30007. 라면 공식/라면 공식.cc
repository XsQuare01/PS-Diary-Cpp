#define MIN 1
#define MAX 26
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b, x;
        cin >> a >> b >> x;
        cout << a * (x-1) + b << "\n";
    }

    return 0;
}
 