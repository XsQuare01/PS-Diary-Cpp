#define MOD 1000000007
#define MAX 2000000

#include<bits/stdc++.h>

using namespace std;

string s;
int len, cnt = 0;
char uarr[3] = {'P', 'E', 'R'};
char larr[3] = {'p', 'e', 'r'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    len = s.length();
    for(int i = 0; i < len; i++){
        char c = s[i];
        if(c >= 'a' && c <= 'z'){
            if(c != larr[i%3]){
                cnt++;
            }
        }
        else{
            if(c != uarr[i%3]){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}