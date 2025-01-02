#include <bits/stdc++.h>
#define MAX 1000000
#define INF 6711
#define MOD 1000000007

using namespace std;

int T, N, K, M;
vector<int> edge[MAX];
int uarr[MAX];
int height[MAX];

void init(int cnt){
    for(int i = 0; i < MAX; i++){
        edge[i] = vector<int>();
        uarr[i] = i;
        height[i] = 1;
    }
    cout << "Scenario "<< cnt <<":\n";
}

int findParent(int a){
    if(uarr[a] == a){
        return a;
    }
    return findParent(uarr[a]);
}

void unionFind(int a, int b){
    int pa = findParent(a);
    int pb = findParent(b);
    if(pa == pb){
        return ;
    }
    if(height[pa] > height[pb]){
        uarr[pb] = pa;
    }
    else if(height[pa] < height[pb]){
        uarr[pa] = pb;
    }
    else{
        uarr[pa] = pb;
        height[pb]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        init(i+1);
        cin >> N >> K;
        for(int j = 0; j < K; j++){
            int a, b;
            cin >> a >> b;
            unionFind(a, b);
        }
        cin >> M;
        for(int j = 0; j < M; j++){
            int a, b, res = 0;
            cin >> a >> b;
            int pa = findParent(a);
            int pb = findParent(b);

            //Debug
            // cout << pa << " " << pb << " ";

            if(pa == pb){
                res = 1;
            }

            cout << res << "\n";
        }
        cout << "\n";
    }


    return 0;
}
