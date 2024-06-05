#define MOD 1000000007
#define MAX 2000000

#include<bits/stdc++.h>

using namespace std;

int N;
int c1, c2, c3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.length() == 7){
            cout << ++c1 << " " << s2;
            c2 = 0;
            c3 = 0;
        }
        else if(s1.length() == 10){
            cout << c1 << "." << ++c2 << " " << s2;
            c3 = 0;
        }
        else{
            cout << c1 << "." << c2 << "." << ++c3 << " " << s2;
        }
        cout << "\n";

    }
    return 0;
}