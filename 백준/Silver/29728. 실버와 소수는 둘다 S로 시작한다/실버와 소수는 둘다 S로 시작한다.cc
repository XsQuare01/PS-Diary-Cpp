#define MAX 5000000
#define MOD 1000000009

#include<bits/stdc++.h>

using namespace std;

int N;
char C;
bool arr[MAX+1] = {false, };
int bres = 0;
int sres = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 2; i <= N; i++){
        if(arr[i]){
            continue;
        }
        for(int j = i + i; j <= N; j += i){
            arr[j] = true;
        }
    }

    arr[1] = true;
    for(int i = 1; i <= N; i++){
        if(arr[i]){
            C = 'B';
            bres++;
        }
        else if(!arr[i] && C == 'B'){
            C = 'S';
            bres--;
            sres += 2;
        }
        else if(!arr[i] && C == 'S'){
            C = 'S';
            sres++;
        }
    }
    cout << bres << " " << sres;
    return 0;
}