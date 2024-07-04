#define MAX 1000
#define INF 2147483648

#include <bits/stdc++.h>

using namespace std;

int X, Y, P1, P2;
int arr[MAX*MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y >> P1 >> P2;
    if(P1 == P2){
        cout << P1;
        return 0;
    }
    arr[P1] = 1; arr[P2] = 1;
    for(int i = 0; i < MAX; i++){
        P1 += X;
        if(arr[P1]){
            cout << P1;
            return 0;
        }
        arr[P1] = 1;
        P2 += Y;
        if(arr[P2]){
            cout << P2;
            return 0;
        }
        arr[P2] = 1;

    }
    cout << -1;
    return 0;
}