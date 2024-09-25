#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string S;
string BS;

bool CheckVowel(){
    int len = S.length();
    for(int i = 0; i < len; i++){
        char c = S[i];
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                break;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> S;
        BS = "";
        if(S == "#"){
            break;
        }

        if(!CheckVowel()){
            cout << S << "ay\n";
            continue;
        }

        int len = S.length();
        bool f = false;
        for(int i = 0; i < len; i++){
            char c = S[i];

            if(f){
                cout << c;
                continue;
            }

            switch(c){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    f = true;
                    cout << c;
                    break;
                default:
                    BS += c;
                    break;
            }
        }
        cout << BS << "ay\n";

    }

    return 0;
}