#define MAX 48
#define INF 500000

#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}
 