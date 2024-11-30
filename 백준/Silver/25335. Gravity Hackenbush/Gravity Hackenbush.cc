#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

int N, M;
int red, blue, green = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
    }
    for(int i = 0; i < M; i++){
        int a, b;
        char color;
        cin >> a >> b >> color;
        switch(color){
            case 'R':
                red++;
                break;
            case 'G':
                green++;
                break;
            case 'B':
                blue++;
                break;
        }
    }

    int red_green = (ceil)(1.0 * green / 2);
    int blue_green = (floor)(green / 2);

    red += red_green;
    blue += blue_green;

    if(red > blue){
        cout << "jhnah917";
    }
    else{
        cout << "jhnan917";
    } 

    return 0;
}
