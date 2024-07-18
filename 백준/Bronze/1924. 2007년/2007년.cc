#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int X, Y;
int cnt = 0;
string res = "";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y;
    for(int i = 1; i < X; i++){
        switch (i){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                cnt += 31;
                break;
            case 2:
                cnt += 28;
                break;
            case 4: case 6: case 9: case 11:
                cnt += 30;
                break;
        }
    }
    cnt += (Y - 1);

    switch(cnt % 7){
        case 0:
            res = "MON";
            break;
        case 1:
            res = "TUE";
            break;
        case 2:
            res = "WED";
            break;
        case 3:
            res = "THU";
            break;
        case 4:
            res = "FRI";
            break;
        case 5:
            res = "SAT";
            break;
        case 6:
            res = "SUN";
            break;
    }
    cout << res;


    return 0;
}   