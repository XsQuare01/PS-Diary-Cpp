#define MAX 1000000
#define MOD 9901
#define INF 200000

#include<bits/stdc++.h>

using namespace std;

int N;
string S;
int T, H, M, D;

int day, night, price;

void TimeCount(){
    if(H >= 22 || H <= 7){
        night++;
    }
    else{
        if(H == 8 && M == 0 && day > 0){
            price += (ceil)(1.0 * day / 60) * 1000;
            day = 0;
        }
        
        day++;
        if(night >= 300){
            night = 0;
            price += 5000;
        }
        else if (night > 0){
            day += night;
            night = 0;
        }
    }

    M++;
    if(M == 60){
        M = 0;
        H++;
        if(H == 24){
            H = 0;
        }
    }
}

void init(){
    price = 0;
    night = 0;
    day = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        init();
        cin >> S >> D;
        string th = "";
        th += S[0];
        th += S[1];
        H = stoi(th);

        string tm = "";
        tm += S[3];
        tm += S[4];
        M = stoi(tm);

        T = 60 * H + M;

        for(int i = 0; i < D; i++){
            TimeCount();
        }

        if(night >= 300){
            price += 5000;
            night = 0;
        }

        //Debug
        // cout << H << ":" << M <<"\n";
        price += (ceil)(1.0 * (day + night) / 60) * 1000;
        cout << price << "\n";
    }
    return 0;
}