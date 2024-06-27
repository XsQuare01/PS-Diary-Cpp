#define MAX 100

#include <bits/stdc++.h>

using namespace std;

long long N, M, D, V;
pair<int, int> rarr[MAX];
pair<int, int> darr[MAX];
int arr[MAX+1];
int maximum = 0;


int main() {
    cin >> N >> M;
    int st = 0;
    for(int i = 0; i < N; i++){
        cin >> D >> V;
        rarr[i] = {D, V};
        for(int j = 0; j < D; st++, j++){
            arr[st] = V;
        }
    }

    st = 0;
    for(int i = 0; i < M; i++){
        cin >> D >> V;
        darr[i] = {D, V};
        for(int j = 0; j < D; j++, st++){
            int accel = V - arr[st];
            maximum = max(maximum, accel);
        }
    }
  cout << maximum;
  return 0;
}