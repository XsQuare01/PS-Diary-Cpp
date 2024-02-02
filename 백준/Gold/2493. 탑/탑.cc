#define MAX 500000
#define INF 987654321


#include<bits/stdc++.h>

using namespace std;

int n;
stack<pair<int, int>> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    s.push({INF, 0});

    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;

        while(!s.empty()){
            auto a = s.top();

            int h = a.first;
            int idx = a.second;

            if(h > t){
                break;
            }
            s.pop();
        }
        cout << s.top().second << " ";
        s.push({t, i});
    }

    return 0;
}