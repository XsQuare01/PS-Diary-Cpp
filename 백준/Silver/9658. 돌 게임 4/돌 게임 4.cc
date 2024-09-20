#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr[1] = 1; // CY
    arr[2] = 0; // SK
    arr[3] = 1;
    arr[4] = 0; 
    for(int i = 5; i <= N; i++){
        if(arr[i-1] || arr[i-3] || arr[i-4]){
            arr[i] = 0;
        }
        else{
            arr[i] = 1;
        }
    }

    if(arr[N]){
        cout << "CY";
    }
    else{
        cout << "SK";
    }
    
    return 0;
}