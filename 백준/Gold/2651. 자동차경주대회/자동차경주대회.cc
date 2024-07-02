#define MAX 100
#define INF 2147483648

#include <bits/stdc++.h>

using namespace std;

struct Node{
    long long dist = INF;
    vector<int> route;

    Node(){};
};

int K, N;
long long darr[MAX + 2];
long long tarr[MAX + 2];
Node dp[MAX + 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;
    for(int i = 1; i <= N+1; i++){  // 사이 거리
        long long d;
        cin >> d;
        darr[i] = darr[i-1] + d;
    }
    for(int i = 1; i <= N; i++){    // 시간
        cin >> tarr[i];
    }
    tarr[N+1] = 0;
    if(darr[N+1] <= K){
        cout << 0 << "\n" << 0;
        return 0;
    }
    dp[0].dist = 0;

    for(int i = 0; i <= N; i++){
        long long i_dist = dp[i].dist;

        for(int idx = i+1; (darr[idx] - darr[i] <= K) && (idx < N+2); idx++){
            long long len = darr[idx] - darr[i];
            long long idx_dist = dp[idx].dist;

            if(idx_dist <= i_dist + tarr[idx]){
                continue;
            }

            
            dp[idx].dist = i_dist + tarr[idx];

            dp[idx].route = vector<int>();
            copy(dp[i].route.begin(), dp[i].route.end(), back_inserter(dp[idx].route));

            if(idx <= N){
                dp[idx].route.push_back(idx);
            }
        }
    }
    auto end_node = dp[N+1];
    cout << end_node.dist << "\n" << end_node.route.size() << "\n";
    for(auto a: end_node.route){
        cout << a << " ";
    }


    return 0;
}