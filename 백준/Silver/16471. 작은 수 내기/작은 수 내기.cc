#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int N;
int narr[MAX];
int marr[MAX];
bool farr[MAX] = {false, };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> narr[i];
    }
    sort(narr, narr+N);
    for(int i = 0; i < N; i++){
        cin >> marr[i];
    }
    sort(marr, marr+N);

    bool f = true;
    for(int i = (N+1)/2 -1 ; i >= 0; i--){
        int v = narr[i];
        int u = upper_bound(marr, marr+N, v) - marr;

        

        while(farr[u] && u < N){
            u++;
        }
        
        if(u >= N){
            f = false;
            break;
        }

        //Debug
        // cout << v << " " << marr[u] << "\n";
        farr[u] = true;
    }

    if(f){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}