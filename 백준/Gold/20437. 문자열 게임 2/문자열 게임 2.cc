#define MAX 10000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;
int t;
int n;
string s;
vector<int> v[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i = 0; i < t; i++){
        for(int i = 0; i < 26; i++){
            v[i] = vector<int>();
        }
        cin >> s >> n;

        int len = s.length();
        for(int j = 0; j < len; j++){
            int a = s[j] - 'a';
            v[a].push_back(j);
        }
        int shortest = INF;
        int longest = -1;
        for(int j = 0; j < 26; j++){
            int vlen = v[j].size();
            if(vlen < n){
                continue;
            }
            for(int k = 0; ; k++){
                int nk = k + n - 1;
                if(nk >= vlen){
                    break;
                }
                shortest = min(shortest, v[j][nk] - v[j][k] + 1);
                longest = max(longest, v[j][nk] - v[j][k] + 1);
            }
        }

        if(longest == -1){
            cout << -1 << "\n";
            continue;
        }
        cout << shortest << " " << longest << "\n";
    }
    return 0;
}