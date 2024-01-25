#define MAX 50000

#include<bits/stdc++.h>

using namespace std;

int n, res = 0;
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    s.push(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        while(!s.empty()){
            int t = s.top();
            if(t < y){
                s.push(y);
                break;
            }

            if(t == y){
                break;
            }
            s.pop();
            res++;
        }
    }
    while(!s.empty()){
        s.pop();
        res++;
    }
    cout << res-1;

    return 0;
}