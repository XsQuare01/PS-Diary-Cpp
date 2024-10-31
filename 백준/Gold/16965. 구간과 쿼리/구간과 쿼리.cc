#define MAX 100
#define MOD 1000000007
#define INF 26

#include<bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> node;
vector<int> edge[MAX];

inline bool canMove(pair<int, int> away, pair<int, int> home){
    return (home.first < away.first && away.first < home.second) || (home.first < away.second && away.second < home.second);
}

void BFS(int st, int ed){
    bool flag[MAX] = {false, };
    queue<int> q;
    flag[st] = true;
    q.push(st);

    while(!q.empty()){
        int idx = q.front();
        q.pop();

        for(auto a: edge[idx]){
            if(flag[a]){
                continue;
            }

            if(a == ed){
                cout << "1\n";
                //Debug
                // cout << idx << "\n";
                return ;
            }

            q.push(a);
            flag[a] = true;
        }
    }

    cout << "0\n";
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int type;
        int a, b;
        cin >> type >> a >> b;
        if(type == 1){
            node.push_back({a, b});
            int idx = node.size() - 1;

            for(int j = 0; j < idx; j++){
                if(canMove(node[j], node[idx])){
                    edge[j].push_back(idx);
                }
                if(canMove(node[idx], node[j])){
                    edge[idx].push_back(j);
                }

                //Debug
                // cout << idx << " ";
                // for(auto a: edge[idx]){
                //     cout << a << " ";
                // }
                // cout << "\n";
            }
        }
        else if(type == 2){
            BFS(a-1, b-1);
        }
    }

    return 0;
}