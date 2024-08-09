#define MAX 50
#define MOD 1000000009

#include<bits/stdc++.h>

using namespace std;

int T;
string S;
int darr[][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> S;
        int len = S.length();
        int x = 0;
        int y = 0;
        int dir = 0;
        int x_max = 0;
        int x_min = 0;
        int y_max = 0;
        int y_min = 0;
        int dx, dy;

        for(int j = 0; j < len; j++){
            dx = darr[dir][0];
            dy = darr[dir][1];
            switch(S[j]){
                case 'F':
                    x += dx;
                    y += dy;
                    break;
                case 'B':
                    x -= dx;
                    y -= dy;
                    break;
                case 'L':
                    dir = (dir + 3) % 4;
                    break;
                case 'R':
                    dir = (dir + 5) % 4;
                    break;
            }
            x_max = max(x_max, x);
            x_min = min(x_min, x);

            y_max = max(y_max, y);
            y_min = min(y_min, y);
        }

        cout << (x_max - x_min) * (y_max - y_min) << "\n";
    }

    return 0;
}