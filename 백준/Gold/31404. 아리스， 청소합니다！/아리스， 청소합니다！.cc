#define MAX 64
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;
 
int h, w;
int r, c, d;
int res = 0;

int arr[MAX][MAX];
int barr[MAX][MAX];
int darr[][2]{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
bool froom[MAX][MAX];
bool droom[MAX][MAX][4];

inline bool InBoundary(int y, int x){
    return y < h && x < w && y >= 0 && x >= 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> r >> c >> d;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            barr[i][j] = s[j] - '0';
        }
    }
    //Debug
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << barr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int cnt = 0;
    while(true){
        if(!InBoundary(r, c)){
            break;
        }
        if(!froom[r][c]){
            froom[r][c] = true;
            d += arr[r][c];
            d %= 4;

            r += darr[d][0];
            c += darr[d][1];
            res += cnt + 1;
            cnt = 0;
            //Debug
            // cout << r << " "  << c  << " " << d << endl;
            continue;
        }

        if(froom[r][c]){
            d += barr[r][c];
            d %= 4;

            if(cnt > 20000){
                break;
            }
            droom[r][c][d] = true;

            r += darr[d][0];
            c += darr[d][1];
            cnt++;
            //Debug
            // cout << r << " "  << c << " " << d << endl;
            continue;
        }
    }

    cout << res;
    return 0;
}