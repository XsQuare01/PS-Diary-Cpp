#define MAX 20
#define MOD 1000000000
#define INF 2100000000

#include<bits/stdc++.h>

using namespace std;

int N, M;
char arr[MAX][MAX];
priority_queue<string, vector<string>, greater<string>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        for(int j = 0; j < M; j++){
            arr[i][j] = S[j];
        }
    }

    for(int i = 0; i < N; i++){
        string s = "";
        for(int j = 0; j < M; j++){
            char c = arr[i][j];
            if(c == '#'){
                if(s.length() >= 2){
                    pq.push(s);
                }
                s = "";
            }
            else{
                s += c;
            }
        }

        if(s.length() >= 2){
            pq.push(s);
        }
    }

    for(int i = 0; i < M; i++){
        string s = "";
        for(int j = 0; j < N; j++){
            char c = arr[j][i];
            if(c == '#'){
                if(s.length() >= 2){
                    pq.push(s);
                }
                s = "";
            }
            else{
                s += c;
            }

        }

        if(s.length() >= 2){
            pq.push(s);
        }
    }
    cout << pq.top();

    return 0;
}