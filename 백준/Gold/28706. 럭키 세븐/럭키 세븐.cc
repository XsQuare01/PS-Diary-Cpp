#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int T;

int N;
char C1, C2;
int I1, I2;
bool arr[7] = {false, };

void init(){
    for(int i = 0; i < 7; i++){
        arr[i] = false;
    }
    arr[1] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        init();

        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> C1 >> I1 >> C2 >> I2;

            bool arr1[7] = {false, };
            if(C1 == '+'){
                for(int k = 0; k < 7; k++){
                    if(!arr[k]){
                        continue;
                    }
                    int idx = (k + I1) % 7;
                    arr1[idx] = true;
                }
            }
            else{
                for(int k = 0; k < 7; k++){
                    if(!arr[k]){
                        continue;
                    }
                    int idx = (k * I1) % 7;
                    arr1[idx] = true;
                }
            }

            bool arr2[7] = {false, };
            if(C2 == '+'){
                for(int k = 0; k < 7; k++){
                    if(!arr[k]){
                        continue;
                    }
                    int idx = (k + I2) % 7;
                    arr2[idx] = true;
                }
            }
            else{
                for(int k = 0; k < 7; k++){
                    if(!arr[k]){
                        continue;
                    }
                    int idx = (k * I2) % 7;
                    arr2[idx] = true;
                }
            }
            for(int k = 0; k < 7; k++){
                arr[k] = arr1[k] | arr2[k];
            }
        }
        if(arr[0]){
            cout << "LUCKY" << "\n";
        }
        else{
            cout << "UNLUCKY" << "\n";
        }
    }

    return 0;
}