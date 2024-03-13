#define MAX 400
#define INF 1000000

#include<bits/stdc++.h>

using namespace std;

int N, D;
char G;
set<string> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> G;
    if(G == 'Y'){
        D = 1;
    }
    if(G == 'F'){
        D = 2;
    }
    if(G == 'O'){
        D = 3;
    }
    for(int i = 0; i < N; i++){
        string ts;
        cin >> ts;
        s.insert(ts);
    }
    cout << s.size() / D;
    return 0;
}
