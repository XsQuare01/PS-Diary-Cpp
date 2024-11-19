#define MAX 4000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int X1, Y1, X2, Y2;
int N;
pair<int, int> arr[MAX+1];
int dist[MAX + 1];
bool not_prime[MAX] = {false, };

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

inline int findDist(int x1, int y1, int x2, int y2){
    return (int)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void findPrime(){
    not_prime[0] = true;
    not_prime[1] = true;

    for(int i = 2; i < MAX; i++){
        if(not_prime[i]){
            continue;
        }

        for(int j = i + i; j < MAX; j += i){
            not_prime[j] = true;
        }
    }
}

void init(){
    for(int i = 0; i <= MAX; i++){
        dist[i] = INF;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    findPrime();
    init();

    cin >> X1 >> Y1 >> X2 >> Y2;
    arr[0] = {X2, Y2};
    int distance = findDist(X1, Y1, X2, Y2);
    if(!not_prime[distance]){
        pq.push({distance, 0});
    }
    

    cin >> N;
    for(int i = 1; i <= N; i++){
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};

        distance = findDist(X1, Y1, x, y);
        // 소수가 아님
        if(not_prime[distance]){
            continue;
        }
        pq.push({distance, i});
    }

    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();

        int distance = a.first;
        int index = a.second;

        if(dist[index] != INF){
            continue;
        }

        dist[index] = distance;
        int x = arr[index].first;
        int y = arr[index].second;

        for(int i = 0; i <= N; i++){
            int tx = arr[i].first;
            int ty = arr[i].second;

            // 이미 거리 측정 완료
            if(dist[i] != INF){
                continue;
            }
            
            // 거리 소수 아님
            int tdist = findDist(x, y, tx, ty);
            if(not_prime[tdist]){
                continue;
            }
            

            pq.push({distance + tdist, i});
        }
    }

    if(dist[0] == INF){
        dist[0] = -1;
    }

    cout << dist[0];
    return 0;
}