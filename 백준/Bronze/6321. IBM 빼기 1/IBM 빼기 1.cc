#define MAX 200000
#define MOD 13

#include<bits/stdc++.h>

using namespace std;

int T, len;
string S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> S;
        len = S.length();

        cout << "String #" << i << "\n";
        for(int j = 0; j < len; j++){
            char c = S[j];
            if(c == 'Z'){
                c = 'A';
            }
            else{
                c += 1;
            }
            cout << c;
        }
        cout << "\n\n";
        

    }
    return 0;
}