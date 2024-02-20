#define MAX 100000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string s;
int n;
stack<char> ls, rs;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> n;
    int len = s.length();
    for(int i = 0; i < len; i++){
        char t = s[i];
        ls.push(t);
    }

    for(int i = 0; i < n; i++){
        char t;
        cin >> t;

        if(t == 'P'){
            char txt;
            cin >> txt;
            ls.push(txt);
        }

        if(t == 'L'){
            if(ls.empty()){
                continue;
            }
            char txt = ls.top();
            ls.pop();
            rs.push(txt);
        }

        if(t == 'D'){
            if(rs.empty()){
                continue;
            }
            char txt = rs.top();
            rs.pop();
            ls.push(txt);
        }

        if(t == 'B'){
            if(ls.empty()){
                continue;
            }
            ls.pop();
        }
    }

    string lres, rres;
    while(!rs.empty()){
        char txt = rs.top();
        rs.pop();
        rres.push_back(txt);
    }

    while(!ls.empty()){
        char txt = ls.top();
        ls.pop();
        lres.push_back(txt);
    }
    reverse(lres.begin(), lres.end());

    cout << lres + rres;
    return 0;

}