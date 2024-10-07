#define MAX 50
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int X, Y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y;
    if(X > 0 && Y > 0){
        cout << 1;
    }
    else if(X > 0 && Y < 0){
        cout << 4;
    }
    else if(X < 0 && Y > 0){
        cout << 2;
    }
    else{
        cout << 3;
    }


    return 0;
}