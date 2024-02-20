#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int res = 1;
    for(int i = 1; ;i++){
        if(n <= res){
            cout << i;
            return 0;
        }
        res += (6 * i);
    }

    return 0;
}