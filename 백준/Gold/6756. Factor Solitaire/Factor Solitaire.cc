#define MAX 5000000

#include<bits/stdc++.h>

using namespace std;

int N;
long long R = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    while(N > 2){
        bool flag = true;
        int sq = ceil(sqrt(N));

        for(int i = 2; i <= sq; i++){
            if(N%i == 0){
                int t = i - 1;
                int k = N/i;
                N = t * k;
                R += t;
                flag = false;
                break;
            }
        }

        if(flag){
            N -= 1;
            R += N;
        }
    }
    if(N == 2){
        R+= 1;
    }
    cout << R;

    return 0;
}