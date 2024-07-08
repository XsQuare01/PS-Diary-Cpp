#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[MAX+1] = {0, };
vector<int> varr[MAX+1];
vector<int> rarr[MAX+1];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int s, e;
        cin >> s >> e;
        varr[s].push_back(e);
        rarr[e].push_back(s);
    }
    q.push(1);

    while(!q.empty()){
        int p = q.front();
        q.pop();

        for(auto a: varr[p]){
            if(!arr[a]){
                arr[a] = p;
                q.push(a);
            }
        }
        for(auto a: rarr[p]){
            if(!arr[a]){
                arr[a] = p;
                q.push(a);
            }
        }
    }
    for(int i = 2; i <= N; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}