#define MAX 500000

#include<bits/stdc++.h>

using namespace std;

int N;
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N; i++){
        q.push(i);
    }

    while(q.size() > 1){
        q.pop();
        int t = q.front();
        q.pop();
        q.push(t);
    }
    cout << q.front();
    
    return 0;
}