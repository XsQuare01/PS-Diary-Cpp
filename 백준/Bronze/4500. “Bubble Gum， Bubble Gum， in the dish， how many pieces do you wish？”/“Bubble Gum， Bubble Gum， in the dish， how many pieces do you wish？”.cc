#define MAX 20

#include<bits/stdc++.h>

using namespace std;

int T, N;
int st_idx, ed_idx;
string input;
vector<string> s_vec;
string st;

int FindName(){
    for(int i = 0; i < s_vec.size(); i++){
        if(s_vec[i] == st){
            return i;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for(int i = 0; i < T; i++){
        getline(cin, input);
        getline(cin, input);
        istringstream ss(input);
        string buff;
        while(getline(ss, buff, ' ')){
            s_vec.push_back(buff);
        }
        getline(cin, st);
        st_idx = FindName();
        cin >> N;
        ed_idx = (N + st_idx - 1) % s_vec.size();
        cout << s_vec[ed_idx] << "\n";
        s_vec.clear();
    }

    return 0;
}