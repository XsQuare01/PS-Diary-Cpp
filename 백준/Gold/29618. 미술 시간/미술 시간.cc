#define MAX 100000

#include<bits/stdc++.h>

using namespace std;

int N, Q;
int tree[4*MAX];
int res[MAX];

void query(int st, int ed, int idx, int a, int b, int x){
    
    if(st > b || ed < a){
        return ;
    }
    if(tree[idx]){
        return ;
    }
    if(st >= a && ed <= b){
        tree[idx] = x;
        for(int i = st; i <= ed; i++){
            if(!res[i]){
                res[i] = x;
            }
        }
        return ;
    }
    int mid = (st + ed) / 2;
    query(st, mid, idx*2, a, b, x);
    query(mid+1, ed, idx*2 + 1, a, b, x);

    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for(int i = 0; i < Q; i++){
        int a, b, x;
        cin >> a >> b >> x;
        query(1, MAX, 1, a, b, x);
    }

    for(int i = 1; i <= N; i++){
        cout << res[i] << " ";
    }
    return 0;
}