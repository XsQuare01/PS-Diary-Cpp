#define MAX 500000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
string S;

queue<int> pq, cq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for(int i = 0; i < N; i++){
        char c = S[i];
        switch(c){
            case 'P':
                pq.push(i);
                break;
            case 'C':
                cq.push(i);
                break;
        }
    }

    int len = min(pq.size(), cq.size());
    for(int i = 0; i < len; i++){
        int pidx = pq.front();
        pq.pop();

        int cidx = cq.front();
        cq.pop();

        swap(S[pidx], S[cidx]);
    }

    cout << S;

    return 0;
}