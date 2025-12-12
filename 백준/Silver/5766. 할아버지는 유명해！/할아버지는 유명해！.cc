#define _CRT_SECURE_NO_WARNINGS
#define MAX 10001
#define INF 300000

#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }

        return a.first < b.first;
    }
};

int N, M;
int flag[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void init(){
    for(int i = 0; i < MAX; i++){
        flag[i] = 0;
    }
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    while(cin >> N >> M){
        if(!N && !M){
            break;
        }

        init();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int t;
                cin >> t;
                flag[t]++;
            }
        }

        for(int i = 0; i < MAX; i++){
            if(!flag[i]){
                continue;
            }

            pq.push({flag[i], i});
        }
        
        pq.pop();

        int snd_max = pq.top().first;
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();

            if(a.first != snd_max){
                break;
            }

            cout << a.second << " ";
        }


        cout << "\n";
    }

    
    return 0;
}