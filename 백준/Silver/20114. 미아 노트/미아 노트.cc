#define MAX 1000000
#define MOD 1000000000
#define INF 10000

#include<bits/stdc++.h>

using namespace std;

int N, H, W;
string arr[MAX];
string res = "";


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++){
        char tchar = '?';
        for(int j = 0; j < H; j++){
            string s = arr[j];
            for(int k = 0; k < W; k++){
                char c = s[i*W + k];
                if(c != '?'){
                    tchar = c;
                    break;
                }
            }
        }

        res += tchar;
    }
    cout << res;

    return 0;
}