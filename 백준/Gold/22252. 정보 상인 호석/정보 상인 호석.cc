#define MAX 100000

#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(a > b){
            return false;
        }
        else{
            return true;
        }
    }
};

int Q, K, B;
int qt, q_cnt = 0, q_idx;
long long R = 0;
string q_str;
map<string, int> marr;
priority_queue<int, vector<int>, cmp> pq[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    for(int i = 0; i < Q; i++){
        int qt;
        cin >> qt >> q_str;
        auto q_iter = marr.find(q_str);
        if(q_iter == marr.end()){
            marr.insert({q_str, q_cnt});
            q_idx = q_cnt++;
        }
        else if(q_iter != marr.end()){
            q_idx = q_iter->second;
        }
        switch(qt){
            case 1:
                cin >> K;
                for(int j = 0; j < K; j++){
                    int t_val;
                    cin >> t_val;
                    pq[q_idx].push(t_val);
                }
                break;
            case 2:
                cin >> B;
                for(int i = 0; i < B; i++){
                    if(pq[q_idx].empty()){
                        break;
                    }
                    R += pq[q_idx].top();
                    pq[q_idx].pop();
                }
                break;
        }
    }
    cout << R;
    return 0;
}