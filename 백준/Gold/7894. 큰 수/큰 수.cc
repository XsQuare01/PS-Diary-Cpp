#define MAX 10000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> varr;
double arr[MAX + 1] = {0.0, }; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<<fixed;
    cout.precision(0);
    
    arr[1] =  log10(1);
    for(int i = 2; i <= MAX; i++){
        arr[i] = arr[i-1] + log10(i);
    }

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        cout << floor(arr[N]) + 1 << "\n";
    }

    return 0;
}
