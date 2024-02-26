#define MAX 500
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string s;
int arr[MAX];
queue<int> q;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int len = s.length();
    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < len; i++){
        arr[i] = s[i] - '0';
        if(arr[i]){
            cnt1++;
        }
        if(!arr[i]){
            cnt0++;
        }
    }
    
    int c1 = 0, c0 = 0;
    for(int i = 0; i < len; i++){
        if(!arr[i]){
            if(c0 < (cnt0 / 2)){
                q.push(0);
            }
            c0++;
            
        }

        if(arr[i]){
            if(c1 >= (cnt1 / 2)){
                q.push(1);
            }
            c1++;
        }
    }
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }

    return 0;
}