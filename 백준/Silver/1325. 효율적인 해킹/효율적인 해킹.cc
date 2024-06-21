#define MAX 10000

#include<bits/stdc++.h>

using namespace std;

int N, M, maximum = -1;
vector<int> varr[MAX + 1];
int rarr[MAX + 1];
queue<int> rq;

int DFS(int idx){
    int cnt = 1;
    stack<int> st;
    bool farr[MAX + 1] = {false, };
    farr[idx] = true;
    st.push(idx);

    while(!st.empty()){
        idx = st.top();
        bool flag = false;
        for(auto new_idx: varr[idx]){
            if(!farr[new_idx]){
                flag = true;
                farr[new_idx] = true;
                cnt++;
                st.push(new_idx);
                break;
            }
        }
        if(!flag){
            st.pop();
        }
    }

    return cnt;
}

int BFS(int idx){
    int cnt = 1; 
    queue<int> qu;
    bool farr[MAX + 1] = {false, };
    farr[idx] = true;
    qu.push(idx);

    while(!qu.empty()){
        idx = qu.front();
        qu.pop();

        for(int node: varr[idx]){
            if(farr[node]){
                continue;
            }
            qu.push(node);
            cnt++;
            farr[node] = true;
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        
        varr[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        rarr[i] = DFS(i);
        if(rarr[i] > maximum){
            rq = queue<int>();
            rq.push(i);
            maximum = rarr[i];
        }
        else if(rarr[i] == maximum){
            rq.push(i);
        }
    }
    while(!rq.empty()){
        cout << rq.front() << " ";
        rq.pop();
    }

    return 0;
}