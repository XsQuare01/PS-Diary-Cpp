#define MAX 500
#define INF 60000000

#include<bits/stdc++.h>

using namespace std;

int h, w;
int arr[MAX];
int larr[MAX];
int rarr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    for(int i = 0; i < w; i++){
        cin >> arr[i];
    }

    int st = min(arr[0], arr[w-1]);
    
    int left = 0;
    int right = w-1;
    for(int j = 0; j < w; j++){
        if(arr[left] < arr[j]){
            left = j;
        }
        larr[j] = arr[left];
    }

    for(int j = w-1; j >= 0; j--){
        if(arr[right] < arr[j]){
            right = j;
        }
        rarr[j] = arr[right];
    }

    int ans = 0;
    for(int i = 0; i < w; i++){
        int res = min(larr[i], rarr[i]);
        if(arr[i] >= res){
            continue;
        }
        ans += res - arr[i];
    }
    
    cout << ans;
    return 0;
}