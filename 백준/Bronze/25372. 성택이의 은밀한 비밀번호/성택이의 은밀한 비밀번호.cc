#define MAX 100000

#include<bits/stdc++.h>

using namespace std;

int N;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(s.length() >= 6 && s.length() <= 9){
            cout << "yes" << "\n";
        }
        else{
            cout << "no" << "\n";
        }
    }
    return 0;
}