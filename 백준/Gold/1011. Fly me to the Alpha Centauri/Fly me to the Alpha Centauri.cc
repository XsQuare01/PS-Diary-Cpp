#define MAX 1000

#include<bits/stdc++.h>

using namespace std;

int T;
int dist;
int height, height_2;
int rest;
int result = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        int x, y;
        cin >> x >> y;

        dist = y - x;
        height = int(sqrt(dist));
        result = 2*height - 1;
        
        height_2 = pow(height, 2);
        rest = dist - height_2;

        if(rest > height){
            result += 2;
        }
        else if(rest > 0){
            result += 1;
        }
        
        cout << result << "\n";
        result = 0;
    }

    return 0;
}