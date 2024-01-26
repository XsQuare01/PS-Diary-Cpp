#define MAX 100

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[MAX+1];
stack<int> s;
int cnt = 0;
int res[MAX + 1];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        bool check[MAX + 1] = {false, };
        
        int u = i;
        while(true){
            int next = arr[u];
            s.push(u);
            check[u] = true;
            if(next == i){
                break;
            }

            if(check[next]){
                s = stack<int>();
                break;
            }
            u = next;
        }

        while(!s.empty()){
            int t = s.top();
            s.pop();
            if(!res[t]){
                cnt++;
            }
            res[t] = 1;
        }
    }

    cout << cnt << "\n";
    for(int i = 1; i<= n; i++){
        if(res[i]){
            cout << i << "\n";
        }
    }
    return 0;
}