#define MAX 100

#include<bits/stdc++.h>

using namespace std;

int N, cnt = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        if(i < 100){
            cnt++;
            continue;
        }
        if(i < 1000){
            int fst = i / 100;
            int snd = (i % 100) / 10;
            int trd = i % 10;

            if((fst - snd) == (snd - trd)){
                cnt++;
                continue;
            }
        }
    }
    cout << cnt;
    return 0;
}