#define MAX 13000

#include <bits/stdc++.h>

using namespace std;

int N, R = 10000;
int p, x, f;
int sarr[MAX + 1] = {0, };
int barr[MAX + 1] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p >> x >> f;
        if(f == -1){    // Sell
            if(!barr[p]){
                sarr[p] += x;
                continue;
            }
            R = p;
            if(barr[p] > x){
                barr[p] -= x;
            }
            else if(barr[p] <= x){
                sarr[p] = x - barr[p];
                barr[p] = 0;
            }
            
        }
        else if(f == 1){    // Buy
            if(!sarr[p]){
                barr[p] += x;
                continue;
            }
            R = p;
            if(sarr[p] > x){
                sarr[p] -= x;
            }
            else if(sarr[p] <= x){
                barr[p] = x - sarr[p];
                sarr[p] = 0;
            }
        }
    }
    cout << R;
    return 0;
}