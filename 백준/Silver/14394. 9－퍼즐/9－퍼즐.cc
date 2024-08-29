#define MAX 100
#define MOD 1000000000
#define INF 2100000000

#include<bits/stdc++.h>

using namespace std;

string S1, S2;
int rcnt1, gcnt1, bcnt1, ycnt1;
int rcnt2, gcnt2, bcnt2, ycnt2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S1 >> S2;
    for(int i = 0; i < 10; i++){
        char c = S1[i];
        switch(c){
            case 'R':
                rcnt1++;
                break;
            case 'G':
                gcnt1++;
                break;
            case 'B':
                bcnt1++;
                break;
            case 'Y':
                ycnt1++;
                break;
            default:
                break;
        }
    }

    for(int i = 0; i < 10; i++){
        char c = S2[i];
        switch(c){
            case 'R':
                rcnt2++;
                break;
            case 'G':
                gcnt2++;
                break;
            case 'B':
                bcnt2++;
                break;
            case 'Y':
                ycnt2++;
                break;
            default:
                break;
        }
    }

    cout << (abs(rcnt1 - rcnt2) + abs(gcnt1 - gcnt2)+ abs(bcnt1 - bcnt2) +  abs(ycnt1 - ycnt2)) / 2;
    return 0;
}