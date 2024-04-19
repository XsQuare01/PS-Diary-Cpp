#define MAX 50
#define INF 500

#include<bits/stdc++.h>

using namespace std;

int W, D, N;

int arr[MAX + 1][MAX + 1];
int res[MAX + 1][MAX + 1];
vector<pair<int, pair<int, int>>> varr;
queue<pair<int, pair<int, int>>> q;

int darr[][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

inline bool InBoundary(int ty, int tx){
    return ty >= 1 && ty <= D && tx >= 1 && tx <= W;
}

bool CheckAltitude(){
    q = queue<pair<int, pair<int, int>>>();

    for(auto a: varr){

        bool check_array[MAX+1][MAX+1] = {false, };
        q.push(a);

        while(!q.empty()){
            auto b = q.front();
            q.pop();

            int z = b.first;
            int x = b.second.first;
            int y = b.second.second;

            check_array[y][x] = true;
            if(res[y][x] >= z){
                continue;
            }
            if(res[y][x] < z){
                res[y][x] = z;
            }
            
            for(auto [dy, dx] : darr){
                int tx = x + dx;
                int ty = y + dy;

                if(!InBoundary(ty, tx)){
                    continue;
                }
                if(check_array[ty][tx]){
                    continue;;
                }
                if(arr[ty][tx] && arr[ty][tx] < z-1){
                    return false;
                }
                if(arr[ty][tx]){
                    continue;
                }
                q.push({z-1, {tx, ty}});
            }
        }
    }

    return true;
}

int SumAltitude(){
    int ret = 0;
    for(int i = 1; i <= D; i++){
        for(int j = 1; j <= W; j++){
            ret += res[i][j];
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> W >> D >> N;
    for(int i = 0; i < N; i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[y][x] = z;
        varr.push_back({z, {x, y}});
    }
    for(int i = 1; i <= D; i++){
        for(int j = 1; j <= W; j++){
            res[i][j] = -INF;
        }
    }

    sort(varr.begin(), varr.end());
    reverse(varr.begin(), varr.end());

    if(CheckAltitude()){
        cout << SumAltitude();
    }
    else{
        cout << "No";
    }
    return 0;
}