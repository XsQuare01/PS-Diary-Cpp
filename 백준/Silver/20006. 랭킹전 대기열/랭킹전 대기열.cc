#define MAX 300
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int p, m;
pair<string, int> arr[MAX];
vector<pair<string, int>> varr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p >> m;
    for(int i = 0; i < p; i++){
        int t;
        string s;
        cin >> t >> s;
        arr[i] = {s, t};
    }

    for(int i = 0; i < p; i++){
        int idx = -1;
        while(true){
            idx++;
            if(varr[idx].size() >= m){
                continue;
            }

            if(varr[idx].size() == 0){
                varr[idx].push_back(arr[i]);
                break;
            }

            int rlev = varr[idx][0].second;
            int plev = arr[i].second;

            if(rlev > plev + 10 || rlev < plev - 10){
                continue;
            }
            varr[idx].push_back(arr[i]);
            break;
        }

    }

    for(int i = 0; i < p; i++){
        if(varr[i].size() == 0){
            break;
        }

        if(varr[i].size() == m){
            cout << "Started!" << "\n";
        }
        if(varr[i].size() < m){
            cout << "Waiting!" << "\n";
        }
        int len = varr[i].size();
        sort(varr[i].begin(), varr[i].end());

        for(auto a: varr[i]){
            cout << a.second << " " << a.first << "\n";
        }

    }
    return 0;

}