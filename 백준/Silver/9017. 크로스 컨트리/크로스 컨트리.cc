#define MAX 1000
#define CMAX 200
#define INF 2000000001

#include<bits/stdc++.h>

using namespace std;


int T, N;
int arr[MAX];
int carr[CMAX + 1];
int narr[CMAX + 1];
float sarr[CMAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        for(int j = 0; j < CMAX; j++){
            carr[j] = 0;
            narr[j] = 0;
            sarr[j] = 0;
        }

        cin >> N;
        for(int j = 0; j < N; j++){
            int idx;
            cin >> idx;
            arr[j] = idx;
            carr[idx]++;
        }

        int rank = 0;
        for(int j = 0; j < N; j++){
            int idx = arr[j];
            if(carr[idx] < 6){
                sarr[idx] = INF;
                continue;
            }
            rank++;
            if(narr[idx] < 4){
                sarr[idx] += rank;
            }
            if(narr[idx] == 4){
                sarr[idx] += (1.0 * rank / 1000);
            }
            if(narr[idx] > 4){
                continue;
            }
            narr[idx]++;
        }

        float res = INF;
        int idx = -1;
        for(int j = 1; j <= CMAX; j++){
            if(sarr[j] == 0){
                break;
            }
            if(res > sarr[j]){
                res = sarr[j];
                idx = j;
            }
        }
        cout << idx << "\n";
    }

    return 0;
}