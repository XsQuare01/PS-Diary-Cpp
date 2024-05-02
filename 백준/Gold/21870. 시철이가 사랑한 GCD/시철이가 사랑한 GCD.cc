#define MAX 200000

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX];

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    return GCD(b, a%b);
}

pair<int, int> BinarySearch(int st, int ed){
    if(st == ed - 1){
        return {arr[st], arr[st]};
    }
    int mid = (st + ed) / 2;
    auto left = BinarySearch(st, mid);
    auto right = BinarySearch(mid, ed);

    int tgcd = GCD(left.first, right.first);
    int tsum = 0;
    if(left.second < right.second){
        tsum = right.second + left.first;
    }
    if(left.second >= right.second){
        tsum = left.second + right.first;
    }
    return {tgcd, tsum};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    auto res = BinarySearch(0, N);
    cout << res.second;

    return 0;
}