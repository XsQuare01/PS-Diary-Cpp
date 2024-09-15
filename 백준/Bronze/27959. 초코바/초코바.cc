#define MAX 1000000
#define MOD 9901
#define INF 200000

#include<bits/stdc++.h>

using namespace std;

int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    if(100 * N >= M){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}