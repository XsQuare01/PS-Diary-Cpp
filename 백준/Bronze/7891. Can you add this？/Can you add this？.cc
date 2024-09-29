#define MAX 300000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        long long a, b;
        cin >> a >> b;
        cout << a + b << "\n";
    }


    return 0;
}