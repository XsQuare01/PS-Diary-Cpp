#define MAX 5000000
#define MOD 13

#include<bits/stdc++.h>

using namespace std;

int N;
string S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin , S);
        
        int c = S[0];
        if(c >= 'a' && c <= 'z'){
            S[0] = c + ('A' - 'a');
        }
        cout << S << "\n";
    }

    return 0;
}