#define MAX 1000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int cnt = 0;
int arr[MAX+1][MAX+1] = {0, };

inline bool InBoundary(int y, int x){
    return y >= 1 && x >= 1 && y <= N && x <= M && !arr[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    cnt = N*M;
    for(int i = 0; i < Q; i++){
        int query;
        cin >> query;
        int dy, dx, y, x;
        switch(query){
            case 1:
                cin >> dy >> dx >> y >> x;
                while(InBoundary(y, x)){
                    arr[y][x] = 1;
                    y += dy;
                    x += dx;
                    cnt--;
                }
                break;
            case 2:
                cin >> y >> x;
                cout << arr[y][x] << "\n";
                break;
            case 3:
                cout << cnt << "\n";
                break;
        }
    }
    return 0;
}   