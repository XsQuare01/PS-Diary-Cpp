#define MAX 1000000
#define MOD 1000000007
#define INF 26

#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 0; i < 10; i++){
        int t;
        cin >> t;
        
        N += t;
    }

    char res;
    switch(N%4){
        case 0:
            res = 'N';
            break;
        case 1:
            res = 'E';
            break;
        case 2:
            res = 'S';
            break;
        case 3:
            res = 'W';
            break;
    }

    cout << res;
    return 0;
}