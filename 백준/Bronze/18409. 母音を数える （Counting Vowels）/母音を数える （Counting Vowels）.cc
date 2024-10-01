#define MAX 500000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
string S;

int res = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for(int i = 0; i < N; i++){
        char c = S[i];
        switch(c){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                res++;
                break;
            default:
                break;
        }
    }

    cout << res;

    return 0;
}