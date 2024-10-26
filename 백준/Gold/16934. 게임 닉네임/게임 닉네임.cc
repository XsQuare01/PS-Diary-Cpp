#define MAX 1000000
#define MOD 1000000007
#define INF 26

#include<bits/stdc++.h>

using namespace std;

int N;
struct Trie{
    Trie* children[INF];
    int cnt = 0;

    void Search(string str, int idx = 0){
        if(idx >= str.length()){
            cnt++;
            string res = str;
            if(cnt > 1){
                res += to_string(cnt);
            }
            cout << res << "\n";
            return ;
        }
        int cidx = str[idx] - 'a';
        if(children[cidx] == NULL){
            cout << str.substr(0, idx+1) << "\n";
            children[cidx] = new Trie();
            children[cidx]->Update(str, idx + 1);
        }
        else{
            children[cidx]->Search(str, idx+1);
        }
        
    }
    void Update(string str, int idx = 0){
        if(idx >= str.length()){
            cnt++;
            return ;
        }

        int cidx = str[idx] - 'a';
        if(children[cidx] == NULL){
            children[cidx] = new Trie();
        }
        children[cidx]->Update(str, idx + 1);
    }
};

Trie trie;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        trie.Search(s);
    }


    return 0;
}