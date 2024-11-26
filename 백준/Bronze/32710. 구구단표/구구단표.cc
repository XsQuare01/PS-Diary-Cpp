#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int N;
int arr[MAX+1] = {false, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 2; i < 10; i++){
        arr[i] = true;
        for(int j = 1; j < 10; j++){
            arr[j] = true;
            arr[i*j] = true;
        }
    }

    if(arr[N]){
        cout << 1;
    }
    else{
        cout << 0;
    }

    return 0;
}
