#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int A, X;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> X;
    for(int i = 0; i < A; i++){
        int t;
        cin >> t;

        if(t < X){
            cout << t << " ";
        }
    }

    return 0;
}
 