#define MAX 100
#define LEN 20
#define INF 2000000001

#include<bits/stdc++.h>

using namespace std;

int N, M, G, S;
int arr[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> G >> S;
        if(G == 1){
            for(int j = S; j <= N; j += S){
                arr[j] = !arr[j];
            }
            continue;
        }
        if(G == 2){
            arr[S] = !arr[S];
            for(int j = 1; S-j > 0 && S+j <= N;j++){
                int le = S-j;
                int ri = S+j;
                if(arr[le] != arr[ri]){
                    break;
                }
                arr[le] = !arr[le];
                arr[ri] = !arr[ri];
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << arr[i];
        if(i%LEN == 0){
            cout << "\n";
        }
        if(i%LEN != 0){
            cout << " ";
        }
    }

    return 0;
}