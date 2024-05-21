#define MAX 10000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(s == "Algorithm"){
            cout << "204" << "\n";
        }
        if(s == "Network"){
            cout << "303" << "\n";
        }
        if(s == "CyberSecurity"){
            cout << "B101" << "\n";
        }
        if(s == "Startup"){
            cout << "501" << "\n";
        }
        if(s == "DataAnalysis"){
            cout << "207" << "\n";
        }
        if(s == "ArtificialIntelligence"){
            cout << "302" << "\n";
        }
        if(s == "TestStrategy"){
            cout << "105" << "\n";
        }
    }

    
    return 0;
}