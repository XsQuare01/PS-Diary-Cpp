#define MAX 200000
#define MOD 1000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, A, B;
int res1 = 1;
int res2 = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> A >> B;

    for(int i = 0; i < N; i++){
        res1 += A;
        res2 += B;

        if(res1 == res2){
            res2 -= 1;
        }
        else if(res1 < res2){
            swap(res1, res2);
        }
    }

    cout << res1 << " " << res2;

    return 0;
}