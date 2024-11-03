#define MAX 2000000
#define MOD 1000000007
#define INF 1844674407370955161

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX + 1];
int le, ri;
long long prefix = 0;
long long minimum = INF;
int res = -1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int k, st;
        cin >> k >> st;
        arr[st]++;
        prefix += (st - 1);

        for(int j = 1; j < k-1; j++){
            int waste;
            cin >> waste;
        }
        int ed;
        cin >> ed;
        arr[ed]++;
        prefix += (ed - 1);
    }

    le = 0;
    ri = 2 * N;
    for(int i = 1; i <= M; i++){
        if(prefix < minimum){
            minimum = prefix;
            res = i;
        }
        //Debug
        // cout << prefix << "\n";

        if(arr[i] != 0){
            ri -= arr[i];
            le += arr[i];
        }

        //Debug
        // cout << ri << " " << le << "\n";

        prefix -= ri;
        prefix += le;


    }

    cout << res;
    return 0;
}