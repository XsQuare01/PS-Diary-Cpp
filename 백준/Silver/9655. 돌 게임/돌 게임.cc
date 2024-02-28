#define MAX 1000
#define HMAX 500000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[MAX + 1];
int darr[] = {1, 3};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr[1] = 1;
    arr[2] = 0;
    arr[3] = 1;
    for(int i = 4; i <= n; i++){
        bool flag = false;
        for(auto a: darr){
            int idx = i - a;
            arr[i] = !(arr[i] & arr[idx]);
        }
    }

    if(arr[n]){
        cout << "SK";
    }
    if(!arr[n]){
        cout << "CY";
    }

    return 0;
}
