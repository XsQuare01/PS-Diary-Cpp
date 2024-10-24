#define MAX 100000
#define MOD 1000000007
#define INF 20

#include<bits/stdc++.h>

using namespace std;

int N, M, T;
vector<int> arr[MAX + 1];
vector<int> rarr[MAX + 1];

bool oneAccess[MAX+1];
bool nAccess[MAX+1];
bool accessable[MAX+1];

void oneBFS(){
    queue<int> q;
    q.push(1);
    oneAccess[1] = true;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto a: arr[t]){
            if(oneAccess[a]){
                continue;
            }
            q.push(a);
            oneAccess[a] = true;
        }
    }
}

void nBFS(){
    queue<int> q;
    q.push(N);
    nAccess[N] = true;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto a: rarr[t]){
            if(nAccess[a]){
                continue;
            }
            q.push(a);
            nAccess[a] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int s, t;
        cin >> s >> t;
        arr[s].push_back(t);
        rarr[t].push_back(s);
    }
    oneBFS();
    nBFS();

    for(int i = 1; i <= N; i++){
        if(oneAccess[i] && nAccess[i]){
            accessable[i] = true;
        }
    }
    


    cin >> T;
    for(int i = 0; i < T; i++){
        int bomb;
        cin >> bomb;
        if(accessable[bomb]){
            cout << "Defend the CTP\n";
        }
        else{
            cout << "Destroyed the CTP\n";
        }
    }

    return 0;
}