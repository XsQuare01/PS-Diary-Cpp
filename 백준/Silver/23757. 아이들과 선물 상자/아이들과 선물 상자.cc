#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

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

int N, M;
int arr[MAX];
priority_queue<int, vector<int>, cmp> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        pq.push(t);
    }
    for(int i = 0; i < M; i++){
        cin >> arr[i];
        int t = pq.top();
        pq.pop();

        if(t < arr[i]){
            cout << 0;
            return 0;
        }
        t -= arr[i];
        pq.push(t);
    }
    cout << 1;
    return 0;
}   