#define MOD 1000000007
#define MAX 200000

#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(long long a, long long b){
        if(a > b){
            return true;
        }
        else{
            return false;
        }
    }
};

int N;
priority_queue<long long, vector<long long>, cmp> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        long long t;
        cin >> t;
        if(t){
            pq.push(t);
        }
    }

    while(true){
        long long p1 = pq.top();
        pq.pop();

        if(pq.empty()){
            cout << p1;
            break;
        }
        long long p2 = pq.top();
        pq.pop();

        if(p1 == p2){
            pq.push(p1 + p2);
        }
        else{
            pq.push(p2);
        }
    }

    return 0;
}