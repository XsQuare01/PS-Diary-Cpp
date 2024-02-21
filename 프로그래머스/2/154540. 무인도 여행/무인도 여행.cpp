#define MAX 100
#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[MAX][MAX];
bool flag[MAX][MAX];
int darr[][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

inline bool InBoundary(int y, int x){
    return x >= 0 && y >= 0 && y < n && x < m && arr[y][x];
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    for(int i = 0; i < n; i++){
        m = maps[i].size();
        for(int j = 0; j < m; j++){
            if(maps[i][j] == 'X'){
                arr[i][j] = 0;
                continue;
            }
            arr[i][j] = maps[i][j] - '0';
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(flag[i][j]){
                continue;
            }
            if(!arr[i][j]){
                continue;
            }
            
            long long sum = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
                auto a = q.front();
                q.pop();
                
                int y = a.first;
                int x = a.second;
                
                if(flag[y][x]){
                    continue;
                }
                
                sum += arr[y][x];
                //Debug
                // cout << sum << endl;
                flag[y][x] = true;
                
                for(auto [dy, dx]: darr){
                    int ty = y + dy;
                    int tx = x + dx;
                    
                    if(!InBoundary(ty, tx)){
                        continue;
                    }
                    if(flag[ty][tx]){
                        continue;
                    }
                    
                    q.push({ty, tx});
                    
                }
            }
            answer.push_back(sum);
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}