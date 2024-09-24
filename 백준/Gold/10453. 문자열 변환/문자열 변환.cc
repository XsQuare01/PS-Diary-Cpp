#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int T;
string A, B;
vector<int> arr, brr;

void init(){
    arr = vector<int>();
    brr = vector<int>();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        init();
        cin >> A >> B;
        int len = A.length();
        int res = 0;

        for(int j = 0; j < len; j++){
            if(A[j] == 'a'){
                arr.push_back(j);
            }
            if(B[j] == 'a'){
                brr.push_back(j);
            }
        }

        for(int j = 0; j < len / 2; j++){
            int a = arr[j];
            int b = brr[j];

            res += abs(a - b);
        }
        cout << res << "\n";
    }

    return 0;
}