#define MAX 10

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX + 1] = {0, };
int len;

void InitDigit(int idx){
    for(int i = idx-1; i >= 0; i--){
        arr[i] = i;
    }
}

bool RoundUpDigit(int idx){
    if(idx >= MAX){
        return false;
    }
    if(arr[idx] == 9){
        return RoundUpDigit(++idx);
    }

    arr[idx] = max(idx, arr[idx] + 1);
    if(arr[idx+1] != 0 && arr[idx] >= arr[idx + 1]){
        return RoundUpDigit(++idx);
    }
    InitDigit(idx);
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    if(N == 0){
        cout << 0;
        return 0;
    }
    
    for(int i = 1; i <= N; i++){
        if(!RoundUpDigit(0)){
            cout << -1;
            return 0;
        }
    }
    //Debug
    bool flag = false;
    for(int i = MAX-1; i >= 0; i--){
        if(arr[i] != 0 || flag){
            cout << arr[i];
            flag = true;
        }
    }
    cout << "\n";

    return 0;
}