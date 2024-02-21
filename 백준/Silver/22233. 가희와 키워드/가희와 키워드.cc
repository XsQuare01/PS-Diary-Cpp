#define MAX 200000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, m;
string arr[MAX];
bool farr[MAX];
// set<string> sset;
int res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    res = n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;

        int idx = 0;
        string ts = "";
        queue<string> q;
        while(true){
            if(idx >= s.length()){
                q.push(ts);
                break;
            }

            if(s[idx] == ','){
                q.push(ts);
                ts = "";
                idx++;
                continue;
            }

            if(s[idx] != ','){
                ts += s[idx++];
                continue;
            }
        }

        while(!q.empty()){
            string ts = q.front();
            q.pop();
            int idx = lower_bound(arr, arr + n, ts) - arr;

            if(arr[idx] == ts && !farr[idx]){
                farr[idx] = true;
                res--;
            }
        }

        cout << res << "\n";
    }
    return 0;

}