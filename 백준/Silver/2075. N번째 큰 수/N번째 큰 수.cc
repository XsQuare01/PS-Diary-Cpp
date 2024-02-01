#define MAX 1500
#define INF 60000000

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[MAX * MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n * n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + (n * n), greater<int>());

    cout << arr[n-1];

    return 0;
}